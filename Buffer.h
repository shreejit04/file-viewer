// Buffer.h

#ifndef _Buffer_h_

#include <fstream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Buffer
{
public:
    void display() const;
    const std::string& file_name() const { return file_name_; }
    bool back_to_previous_file();
    void move_to_next_page();
    void move_to_previous_page();
    bool open(const std::string& file_name);
    bool go(const int& link_number);
    bool search(const std::string& input);
    void set_window_height(int h) { window_height_ = h; }
    void set_window_width(int w) { window_width_ = w; }
    void add_word(const std::string& word, std::string& line);
    std::string process_anchor(const std::string& line, const std::string& f_name, const std::string& text, int& count);

private:
    std::vector<std::string> v_lines_;
    int ix_top_line_ = 0;
    std::string file_name_;
    int window_height_;
    int window_width_;
    std::vector<std::string> history;
    std::vector<std::string> anchor_files;
};

inline void Buffer::move_to_next_page()
{
    ix_top_line_ += window_height_;
    if (ix_top_line_ >= v_lines_.size())
        ix_top_line_ -= window_height_;
}

inline void Buffer::move_to_previous_page()
{
    ix_top_line_ -= window_height_;
    if (ix_top_line_ < 0)
        ix_top_line_ = 0;
}

inline bool Buffer::go(const int& link_number)
{
    std::string file = anchor_files[link_number - 1];
    if (!open(file))
        return false;
    else
        return true;
}

inline bool Buffer::back_to_previous_file()
{
    history.pop_back();
    if (!open(history.back()))
        return false;
    else {
        history.pop_back();
        return true;
    }
}

#endif