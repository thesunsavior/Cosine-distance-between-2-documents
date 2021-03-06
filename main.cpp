#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tgmath.h>
#define PI 3.141592653589793238463

using namespace std;

class document
{
    unordered_map<string, int> bag_of_words;

public:
    bool contains(string word)
    {
        if (bag_of_words.count(word) == 1)
            return true;

        return false;
    }

    int get_value(string word)
    {
        if (!contains(word))
            return 0;

        return bag_of_words[word];
    }

    void insert(string word)
    {
        if (contains(word))
            bag_of_words[word]++;
        else
            bag_of_words[word] = 1;
    }

    int dot_product(document &doc2)
    {
        int sum = 0;
        for (auto iter = cbegin(bag_of_words); iter != cend(bag_of_words); ++iter)
            sum += get_value(iter->first) * doc2.get_value(iter->first);

        return sum;
    }

    // square euclid length of current doc words vector
    double sq_euclid_length()
    {
        double sum = 0.0;
        for (auto iter = cbegin(bag_of_words); iter != cend(bag_of_words); ++iter)
            sum += iter->second * iter->second;

        return sum;
    }

    // cosine distance of the currently consider doc with doc2
    double cos_similarity(document &doc2)
    {
        // sqrt here to get small marginal error
        return dot_product(doc2) / sqrt(sq_euclid_length() * doc2.sq_euclid_length());
    }
};

int main()
{
    string first_doc_path = "input1.txt";
    string second_doc_path = "input2.txt";

    cin >> first_doc_path;
    cin >> second_doc_path;

    document doc1;
    document doc2;
    ifstream inFile;

    // process file 1
    inFile.open(first_doc_path);
    // check for file error
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string word;
    while (inFile >> word)
    {
        doc1.insert(word);

        // added this to avoid last line repeat error
        if (inFile.eof())
            break;
    }

    inFile.close();

    // process doc 2
    inFile.open(second_doc_path);
    // check for file error
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> word)
    {
        doc2.insert(word);
        // added this to avoid last line repeat error
        if (inFile.eof())
            break;
    }

    inFile.close();

    // radiant
    cout << acos(doc1.cos_similarity(doc2));
    return 0;
}
