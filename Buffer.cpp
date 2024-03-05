// Buffer.cpp

#include "Buffer.h"

using namespace std;

void Buffer::display() const
{
    int ix_stop_line_ = ix_top_line_ + window_height_;
    for (int i = ix_top_line_; i < ix_stop_line_; ++i) {
        if (i < v_lines_.size())
            cout << std::setw(6) << i + 1 << "  " << v_lines_[i];
        cout << '\n';
    }
}

bool Buffer::open(const string& new_file_name)
{
    std::ifstream file(new_file_name);
    if (!file)
        return false;

    v_lines_.clear();
    // Note: the vector is cleared only after we know the file
    // opened successfully.

    string word, f_name, text, line;
    int count = 0;
    while (file >> word) {
        if (word == "<a") {
            file >> f_name >> text;
            word = process_anchor(word, f_name, text, count);
            add_word(word, line);
        }
        else 
            add_word(word, line);
    }
    v_lines_.push_back(line);
    
    file_name_ = new_file_name;
    history.push_back(new_file_name);
    ix_top_line_ = 0;
    return true;
}

bool Buffer::search(const string& input)
{
    bool found = false;

    for (int index = ix_top_line_; (index < v_lines_.size()) && (found == false); index++) {
        if (v_lines_[index].find(input) != string::npos)
        {
            ix_top_line_ = index;
            found = true;
        }
        else found = false;
    }
    return found;
}

std::string Buffer::process_anchor(const string& line, const string& f_name, const string& text, int& count)
{
    anchor_files.push_back(f_name);
    string new_string = '<' + text + '[' + to_string(count + 1) + ']';
    count++;
    return new_string;
}

void Buffer::add_word(const string& word, string& line)
{
    if (word == "<p>") {
        v_lines_.push_back(line);
        line.clear();
        v_lines_.push_back(line);
        }
    else if (word == "<br>") {
        v_lines_.push_back(line);
        line.clear();
        }
    else
    {
        if ((line.length() + word.length() + 1) <= window_width_)
            line = line + word + " ";
        else
        {
            v_lines_.push_back(line);
            line.clear();
            line = line + word + " ";
        }
    }
}