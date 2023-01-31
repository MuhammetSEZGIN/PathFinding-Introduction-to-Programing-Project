
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <sstream>

using namespace std;


void takeNodes(vector<string>& nodes) {

    string sLine;
    fstream new_file;
    new_file.open("input.txt", ios::in);

    if (new_file.good())
    {
        getline(new_file, sLine);
    }

    stringstream test(sLine);
    string textInput;

    while (getline(test, textInput, ',')) {
        nodes.push_back(textInput);
    }

    new_file.close();

}


void takePath(vector<string>& node1, vector<string>& node2) {

    string sLine;
    fstream new_file;
    new_file.open("input.txt", ios::in);

    string textInput;
    int count = 0;

    while (getline(new_file, sLine)) {

        if (sLine == "Paths:")
            break;
        if (count > 1) {
            textInput = sLine.substr(0, 2);
            node1.push_back(textInput);

            textInput = sLine.substr(4, 2);
            node2.push_back(textInput);
        }
        count++;
    }

    new_file.close();

}

int findStartOfGivenPath() {
    string sLine;
    fstream new_file;
    new_file.open("input.txt", ios::in);

    string textInput;
    int count = 0;

    while (getline(new_file, sLine)) {

        if (sLine != "Paths:") {
            count++;
        }
        else
            break;
    }
    new_file.close();
    return count;

}

void takeGivenPath(vector<string>& node) {

    string sLine;
    fstream new_file;
    new_file.open("input.txt", ios::in);

    string textInput;
    int count = 0;

    while (getline(new_file, sLine)) {

        if (count > findStartOfGivenPath()) {
            node.push_back(sLine);
        }
        count++;
    }
    new_file.close();
}

int getIndex(vector<string> v, string K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    else {
        return -1;
    }
}


vector<int> getIndeces(char charNode, vector<string> nodes) {
    vector<int> temp; // 0,1
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].at(0) == charNode) {
            temp.push_back(getIndex(nodes, nodes[i]));

        }
    }
    return temp;
}



bool isPathExist(char first, char second, vector<string>nodes, int** pathMatrix) {
    vector<int> temp1 = getIndeces(first, nodes);
    vector<int> temp2 = getIndeces(second, nodes);

    for (int i = 0; i < temp1.size(); i++)
    {
        for (int j = 0; j < temp2.size(); j++) {

            if (pathMatrix[temp1[i]][temp2[j]] == 1) {

                return true;
            }

        }

    }
    return false;
}

bool isGivenPathExist(int i, vector<string> givenPaths, vector<string>nodes, int** pathMatrix) {


    for (int j = 0; j < givenPaths[i].size() - 1; j++)
    {
        if (!isPathExist(givenPaths[i].at(j), givenPaths[i].at(j + 1), nodes, pathMatrix)) {
            return false;

        }
    }

    return true;
}

int main() {


    vector<string> nodes;
    vector<string> pathFirst;
    vector<string> pathSecond;
    vector<string> givenPaths;
    takeNodes(nodes);
    takePath(pathFirst, pathSecond);
    takeGivenPath(givenPaths);

    // 2D array dynamically

    int const size = nodes.size();

    int** pathMatrix = new int* [size];
    for (int i = 0; i < size; i++) {
        pathMatrix[i] = new int[size];
    }

    // Firstly all paths are 0

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            pathMatrix[i][j] = 0;
        }
    }

    // Complate adjacency matrix. Give 1 if there is a path between nodes. 

    for (int i = 0; i < pathFirst.size(); i++) {

        pathMatrix[getIndex(nodes, pathFirst[i])][getIndex(nodes, pathSecond[i])] = 1;

    }

    cout << "Adjacency Matrix of given graph: " << endl << "   ";

    for (int i = 0; i < size; i++)
        cout << nodes[i];

    for (int i = 0; i < size; i++)
    {

        cout << endl;
        for (int j = 0; j < size; j++) {

            if (j == 0)
                cout << nodes[i] << " ";
            cout << pathMatrix[i][j] << " ";
        }
    }

    ofstream MyFile("output.txt");



    for (int i = 0; i < givenPaths.size(); i++) {
        if (isGivenPathExist(i, givenPaths, nodes, pathMatrix)) {
            MyFile << givenPaths[i] << " " << "yes" << endl;
        }
        else
            MyFile << givenPaths[i] << " " << "no" << endl;

    }


    MyFile.close();

    return 0;
}
