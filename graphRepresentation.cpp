#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class graphRepresentation
{

    vector<int> graphOutEdges;
    vector<int> nodeOutEdges;

    public:

    void readgraph()
    {
        int counter=0;
        int numberScan;
        int lastNumberScan=-1;

        ifstream inputFile ("graph.txt");
        if (inputFile.good())
        {
            while (inputFile >> numberScan)
            {
                counter++;
                if(numberScan>=nodeOutEdges.size())
                {
                    nodeOutEdges.resize(numberScan+1,0);
                }

                if(numberScan != lastNumberScan)
                {
                    nodeOutEdges[lastNumberScan + 1] = counter - 1;
                    lastNumberScan = numberScan;
                }

                inputFile >> numberScan;
                graphOutEdges.push_back(numberScan);   
            }
            nodeOutEdges[0] = counter-1;
        }
        
    inputFile.close();
    }

    void displaygraphOutEdges()
    {
        cout<< endl << "graphOutEdges: ";
        for (int i = 0; i < graphOutEdges.size(); ++i)
        {
            cout <<graphOutEdges[i] << " ";
        }
    }

    void displaynodeOutEdges()
    {
        cout << "nodeOutEdges: ";
        for (int i = 0; i < nodeOutEdges.size(); ++i)
        {
            cout << nodeOutEdges[i] << " ";
        }
    }
} ;

int main()
{
    graphRepresentation graphObj;
    graphObj.readgraph();
    graphObj.displaynodeOutEdges();
    graphObj.displaygraphOutEdges();
    return 0;
}
