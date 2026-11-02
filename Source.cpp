#include <iostream>
#include <string>
using namespace std;

    const int SIZE = 5;
// Abstract Base Class
class Media {
protected:
    string title;
    string creator;
    int duration;

public:
    Media(string t, string c, int d)
        : title(t), creator(c), duration(d) {
    }
    void prtBase() const {
        cout << "Title :" << title << '\n'
            << "Creator :" << creator << '\n'
            << "Duration :" << duration << '\n';
    };

    virtual ~Media() {}

    string getTitle() const {
        return title;
    }

    virtual void displayInfo() const = 0;
    virtual void play() const = 0;
};

// Derived Class: Song
class Song : public Media {
private:
    string genre;

public:
    Song(string t, string c, int d, string g)
        : Media(t, c, d), genre(g) {
    }

    void displayInfo() const override {
        prtBase();
        cout << "Genre :" << genre<<'\n';
    };

    void play() const override {
        cout << "Now playing :" << getTitle() << '\n';
    }
};

// Derived Class: Podcast
class Podcast : public Media {
private:
    int episodeNumber;

public:
    Podcast(string t, string c, int d, int e)
        : Media(t, c, d), episodeNumber(e) {
    }

    void displayInfo() const override {
        prtBase();
        cout << "Episode Number :" << episodeNumber<< '\n';
    }

    void play() const override {
        cout << "playing Podcast :" << getTitle() << '\n';
    }
};

// Derived Class: Audiobook
class Audiobook : public Media {
private:
    string narrator;

public:
    Audiobook(string t, string c, int d, string n)
        : Media(t, c, d), narrator(n) {
    }

    void displayInfo() const override {
        prtBase();
        cout << "Narrator :" << narrator << '\n';
    }

    void play() const override {
        cout << "Playing Audiobook :" << getTitle() << '\n';
    }
};

// Search Function
int searchMedia(
    Media* library[],
    //Why pass the size when its set as a constant
    // int size,
    const string& target
) {
    // TODO: Loop through library
    // Compare titles using getTitle()
    // Return matching index or -1

    for (int i = 0; i < SIZE; i++)
    {
        if (library[i]->getTitle() == target) {
            cout << "Found at :";
            return i;
        };
    };


    cout << "not found";
    return -1;
}
// Search Function 2
Media* searchMedia(
    Media* library[],
    //Why pass the size when its set as a constant
    // int size,
    int target
) {
    // TODO: Loop through library
    // Compare titles using getTitle()
    // Return matching index or -1

    if (target < SIZE) { return library[target]; }


    cout << "\n not found \n";
    return nullptr;
}




int main() {

    Media* library[SIZE] = {
    new Song("Hello","Adele",4,"Pop"),
    new Song("World","The Bee Gees",3,"Pop"),
    new Podcast("How to eat sandwhich","Mr.Mayonaise",56,1450),
    new Podcast("Pond","peppernotreal",25,10),
    new Audiobook("How to Read","Booker B Booker",165,"Professor Bookmaxxing")
    };

    // TODO: Create 5 objects using new
    // 2 Songs, 2 Podcasts, 1 Audiobook

    cout << "=== RECMIX MEDIA LIBRARY ===\n";

    // TODO: Use a loop to display and
    // play each media item
    for (int i = 0; i < SIZE; i++)
    {
        cout << '\n';
        library[i]->displayInfo();
        library[i]->play();
    }

    cout << "\n=== SEARCH RESULTS ===\n";

    cout<<searchMedia(library, "World")<<'\n';

    // TODO: Perform a successful search
    cout << searchMedia(library, "Words") << '\n';
    // TODO: Perform an unsuccessful search

    cout << searchMedia(library, 1)->getTitle << '\n';

    cout << searchMedia(library, 6) << '\n';
    // TODO: Delete all dynamically
    // allocated objects

    delete [] &library;
 

    return 0;
}