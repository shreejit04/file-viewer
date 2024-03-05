# file-viewer

**COMPONENT: FIleViewer.cpp**

Public methods:

    ●	void display(): User interface; shows options to user, displays error messages when commands are not done correctly.
    ●	void execute_command(char command, bool& done): Has the following commands:
      ○ next: moves to the next page
      ○ previous: moves to the previous page
      ○ open: opens file using file name; if file cannot be opened, displays error message
      ○ search: searches through file for a string; if string cannot be found, displays error message
      ○ back: returns to file opened previously
      ○ go: goes to a file using a specific number assigned to each file ○ quit: quits file viewer ● void run(): Runs the file viewer.
      Implementation note: Holds the lines of text in a Buffer object. The displaying of the buffer contents and the execution of the commands is delegated to the Buffer object.
      Collaborator: Buffer
_____________________________________________________________________________________________
COMPONENT: Buffer.cpp

A buffer for a simple file viewer. Holds the lines of text and executes commands on them. Displays the contents of the buffer.  See program specification for details on commands.

**Public methods:**

    ●	Buffer(): Compiler-generated. Creates an empty buffer.
    ●	void display() const: Displays the lines of text that the user is currently viewing.
    ●	const string& new_file_name() const: Returns the name of the file.
    ●	bool open(const string& new_file_name): Opens the file, uses anchors and line spacing to make sure text is formatted correctly; adds file to history to be used in back function.
      ○ Executes the corresponding file viewer command on the buffer. See program specification for details.  The method open returns true if successful.
    ●	bool search(const string& input): Loops through the file to find a specific string within that file; returns false if string is not found.
    ●	string process_anchor(const string& line, const string& f_name, const string& text): assigns each file an anchor, a number, and returns that anchor.
    ●	void add_word(const string& word, string& line): makes sure the line fits within the window width, if it does not fit, then it moves the word to the next line.
    Implementation note: Stores each line of text as a string and all the lines in a vector. Also stores the index of the line currently displayed at the top of the window, as well as the name of the file and the window height.
_____________________________________________________________________________________________
COMPONENT: FIleViewer.h

Declarations of the following methods:

**Public methods:**

Design Document

    ●	void run()

**Private methods:**

    ●	void display()
    ●	void execute_command(char command, bool& done): executes each command depending on what the user commands.
    ●	Buffer buffer_: creates buffer_ object to run corresponding commands inside the buffer.
    ●	int window_height_
    ●	int window_width_
    ●	string error_message_: message to display in case of any error. Can be customized as per each error/command.
_____________________________________________________________________________________________
COMPONENT: Buffer.h

Declarations of the following methods:

**Public methods:**

    ●	void display() const
    ●	const string& file_name() const: returns file name.
    ●	bool back_to_previous_file(): Function to move to the previous file as saved in history.
    ●	void move_to_next_page(): Function to move to the next set of lines in the visible window.
    ●	void move_to_previous_page(): Function to move to the previous set of lines in the visible window. ● bool open(const string& file_name): Function to open a file.
    ●	bool go(const int& link_number): Function to go into a link,
    ●	bool search(const string& input): Search algorithm that looks for the first occurrence of a string in a file and starts reading from that particular line.
    ●	void set_window_height(int h): Number of lines in a window.
    ●	void set_window_width(int w): Number of characters (or less given that a new word exceeds the limit) per line.
    ●	void add_word(const string& word, string& line): ensures that the window width is not exceeded and passes the correct number of words/characters per line.
    ●	string process_anchor(const string& line, const string& f_name, const string& text): processes any anchor, saves anchor names, and returns appropriate words to be printed.
    
**Private methods:**

    ●	vector<string> v_lines_: stores file lines.
    ●	int ix_top_line_ = 0: sets the first line to 0, to know how many lines to display on the screen to the user.
    ●	string file_name
    ●	int window_height_: Total number of visible lines in a window 
    ● int window_width_: Total characters (or less) in a particular line
    ●	vector<string> history: stores the names of previous files visited.
    ●	vector<string> anchor_files: stores anchor file names such that they can be accessed using an index value.
