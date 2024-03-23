#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User {
protected:
    string username, email, password;
public:
    User(string username, string email, string password) : username(username), email(email), password(password) {}

    // Method for password hashing 
    void Hash(string password) {
        for (int i = 0; password[i] != '\0'; i++) {
            password[i] = password[i] - 62;
        }
        this->password = password;
    }

    // Method for password dehashing
    string DeHash() const {
        string dehashedPassword = password;
        for (int i = 0; dehashedPassword[i] != '\0'; i++) {
            dehashedPassword[i] = dehashedPassword[i] + 62;
        }
        return dehashedPassword;
    }

    // Method for user verification
    bool verifyPassword(string inputPassword) const {
        return password == inputPassword;
    }
};

class Post {
    int post_Id, likes, comment_count, view_count;
    string content;
    vector<string> comments;
public:
    Post(string content, vector<string> &comments,int post_Id) : post_Id(post_Id),likes(1), comment_count(comments.size()), view_count(0), content(content), comments(comments) {}

    void set_postId(int post_Id) {
        this->post_Id = post_Id;
    }

    void add_comment(string comment) {
        comment_count++;
        comments.push_back(comment);
    }

    void add_like() {
        likes++;
    }

    void add_view() {
        view_count++;
    }

    void display() {
         view_count++;
        cout << "Content: " << content << endl << "Likes: " << likes << endl<<"Views: "<<view_count<<endl
            << "Post Id: " << post_Id << endl << "Comments: " <<comment_count<< endl;
        for (int i = 0; i < comments.size(); i++) {
            cout << comments[i] << endl;
        }
    }

    int get_like_count() const {
        return likes;
    }

    int get_comment_count() const {
        return comment_count;
    }

    int get_view_count() const {
        return view_count;
    }
};

class Regular_User : public User {
    static const int posting_limit = 5;
    static const int Max_feed_Size = 10;
    int feed_count, limit_count;
    vector<Post*> feed;
public:
    Regular_User(string username, string email, string password) : User(username, email, password), feed_count(0), limit_count(0) {}

    void limited_posting() {
        if (limit_count < posting_limit) {
            limit_count++;
        } else {
            cout << "Can't add Post. Posting limit reached." << endl;
        }
    }

    void like_post(Post& post) {
        post.add_like();
    }

    void comment_on_post(string comment, Post& post) {
        post.add_comment(comment);
    }

    void add_feed(Post* post) { // Accepting pointer to Post
        if (feed_count < Max_feed_Size) {
            feed.push_back(post);
            feed_count++;
        } else {
            cout << "Can't add feed. Feed space is full." << endl;
        }
    }

    void view_feed() const {
        for (int i = 0; i < feed_count; i++) {
            feed[i]->display(); // Dereferencing pointer to access Post object
            cout<<endl;
        }
    }
};

const int Regular_User::posting_limit;
const int Regular_User::Max_feed_Size;

class Business_User : public User {
    static const int promotion_limit = 10;
    int promotion_count;
public:
    Business_User(string username, string email, string password) : User(username, email, password), promotion_count(0) {}

    void post_promotion(Post& post) {
        int lc = post.get_like_count();
        int vc = post.get_view_count();
        for (int i = 0; i < lc * 2; i++) {
            post.add_like();
        }
        for (int j = 0; j < vc * 3; j++) {
            post.add_view();
        }
    }

    void promotion_limit_check() {
        if (promotion_count < promotion_limit) {
            promotion_count++;
        } else {
            cout << "Can't Promote Post. Promotion limit reached." << endl;
        }
    }
};

const int Business_User::promotion_limit;

int main() {
    vector<string> comments1 ={"Goood","Awesome","Nice","WonderFull"};
    vector<string> comments2 ={"Hero","Great","Superb"};
    Regular_User regularUser("syed fahad shah", "fahadshahf7@gmail.com", "Fahad123");
    Business_User businessUser("Student", "K230062@nu.edu.pk", "Student123");

    Post post1("Ki hal chal!!!",comments1,62);
    Post post2("thk ho na!!!",comments2,58);
    regularUser.add_feed(&post1);
    regularUser.add_feed(&post2);

    businessUser.post_promotion(post1);

    // Display feed
    cout << "Regular User Feed:" << endl<<endl;
    regularUser.view_feed();
    return 0;
}
