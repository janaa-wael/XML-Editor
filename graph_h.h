#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include "visualization.cpp"
#include "XML_minifying.h"
#include "file_processing.h"
#include "validate_fix.h"

using namespace std;

// Structure to represent a node in the tree
struct TreeNode {
    string tagName;
    string value;
    vector<TreeNode*> children;

    TreeNode(string name, string val = "") : tagName(name), value(val) {}
};

// Function declarations
TreeNode* parseXML(const string& xml, size_t& pos);
string readFile(const string& fileName);
void buildGraph(TreeNode* root, map<int, vector<int>>& graph);
void buildIdNameMap(TreeNode* root, map<int, string>& idNameMap);
vector<pair<int, string>> findMostInfluentialUsers(const map<int, vector<int>>& graph, const map<int, string>& idNameMap);
void buildFollowingMap(const map<int, vector<int>>& graph, map<int, vector<int>>& followingMap);
vector<pair<int, string>> findMostActiveUsers(const map<int, vector<int>>& graph, const map<int, string>& idNameMap, const map<int, vector<int>>& followingMap);
void suggestUsersToFollowForId(const map<int, vector<int>>& graph, int userId);
vector<int> findMutualFollowers(const map<int, vector<int>>& graph, const vector<int>& users, size_t n);
string toLower(const string& str);
void searchByTopic(TreeNode* root, const string& topic, vector<string>& bodies);
void searchByWord(TreeNode* root, const string& word, vector<string>& bodies);
void searchByWord(TreeNode* root, const string& word);

#endif // HEADER_H