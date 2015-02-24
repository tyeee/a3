// Blog.h

#include "error.h"
#include "Blog_base.h"
// You may include any other C/C++ libraries you need here.
// Do not include any non-libraries (besides Blog_base.h and error.h).


// Implement your Blog class in this file.

struct content{
	string title;
	string body;
};

typedef vector<content> content_table;


class Blog : public Blog_base {
private:
	string title_blog;
	string author;
	content_table blog_content;


public:
	Blog(const string& tb, const string& a)
		: title_blog(tb), author(a)   // initialization list
	{
    	if (tb == "") error("Title cannot be empty");
    	if (a == "") error("Author cannot be empty");
	}

	// Pre-condition:
    //    none
    // Post-condition:
    //    Returns the title of this blog.
    // Performance:
    //    Should run in a very quick constant time.
    string get_title() const {
    	return title_blog;
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the author of this blog.
    // Performance:
    //    Should run in a very quick constant time.
    string get_author() const {
    	return author;
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    Returns the number of postings in this blog.
    // Performance:
    //    Should run in a very quick constant time.
    int num_postings() const {
    	return blog_content.size();
    }

    // void print_bars(const string title){
    // 	for(int i = 0; i < title.size(); i++) cout << "-";
    // }

    // Pre-condition:
    //    none
    // Post-condition:    
    //    Returns an index, i, such that 0 <= i < num_postings indicating the
    //    position in this blog of the first posting whose title equals the
    //    passed-in title. If no posting in the blog has a matching title,
    //    then -1 is returned.
    // Performance:
    //    Runs in time proportional to num_postings() (or better).
	int get_posting_index(const string& t) {
    	for(int i = 0; i < blog_content.size(); i++){
    		if(blog_content.title[i] == t) return i;
    	} else {
    		return -1;
    	}
    }

    // Pre-condition:
    //    title.size() > 0 and body.size() > 0, 
    // Post-condition:
    //    Adds a posting with the given title and body to this blog.
    // Performance:
    //    Should be no worse than the average performance of push_back on the 
    //    standard vector class.
    void append_posting(const string& title, const string& body) {
    	blog_content.push_back();
    	blog_content.title[content.size - 1] = title;
    	blog_content.body[content.size - 1] = body;
    }


    // Pre-condition:
    //    title.size() > 0 and body_lines.size() > 0, 
    // Post-condition:
    //    Adds a posting with the given title and body to this blog. The body
    //    consists of all the strings in body_lines joined together with an
    //    extra '\n' added to the end of each line except for the last (i.e.
    //    don't add an extra '\n' to the last line of body_lines).
    // Performance:
    //    Should be no worse than the average performance of push_back on the 
    //    standard vector class.
    virtual void append_posting(const string& title, const vector<string>& body_lines) {

    	blog_content.push_back();
    	blog_content.title[content.size() - 1] = title;

    	string body = body_lines[0];
    	for(int i = 1; i < body_lines.size(); i++){
    		body = body + "\n" + body_lines[i] ;
    	}

    	blog_content.body[content.size - 1] = body;

    }

    // Pre-condition:
    //    0 <= i < num_postings()
    // Post-condition:
    //    Deletes the posting at index position i. The first posting appended
    //    to the blog is at index position 0, the second is at index position 1, 
    //    and so on.
    // Performance:
    //    Should take time proportional to num_postings() (or better).
    virtual void delete_posting(int i) {
    	content_table holder;
    	for(int a = 0; a < blog_content.size() -1; a++){
    		holder.push_back();
    	}

    	for(int a = 0; a < i; a++){
    		body_holder[a] = holder.blog_content[a];
    	}

    	for(int a = i; a > i && a < blog_content.size(); a++){
    		body_holder[a-1] = holder.blog_content[a];
    	}


    	blog_content = holder;

    }

    void print_lines(string t){
    	for(int i = 0; i < t.size(); i++){
    		cout << "-";
    	}
    }

    // destructor
    virtual ~Blog() { 

    	cout << title_blog << "\n";
    	cout << author << "\n";


    	for(int i = 0; i < blog_content.size(); i++){
    		cout << "\n";
    		print_lines(blog_content.title[blog_content.size()- i - 1]);
    		cout << "\n";
    		cout << blog_content.title[blog_0content.size()- i - 1];
    		cout << "\n";
    		print_lines(blog_content.title[blog_content.size()- i - 1]);
    		cout << "\n";
    		cout << blog_content.body[blog_content.size()- i - 1];
			cout << "\n";
    	}

    }
};
