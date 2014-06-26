#include <iostream>

#include "server.h"
#include "orbfeatureextractor.h"
#include "orbsearcher.h"
#include "wordindex.h"


using namespace std;

int main(int argc, char** argv)
{
    cout << "Pastec Index v0.0.1" << endl;

    if (argc < 2)
    {
        cout << "Usage :" << endl
             << "./ImageIndexer visualWordList" << endl;
        return 1;
    }

    Index *index = new Index("backwardIndex.dat");
    WordIndex *wordIndex = new WordIndex(string(argv[1]));
    ORBFeatureExtractor *ife = new ORBFeatureExtractor(index, wordIndex);
    ORBSearcher *is = new ORBSearcher(index, wordIndex);
    Server *s = new Server(ife, is, index);

    s->start();

    s->join();

    delete s;
    delete index;

    return 0;
}
