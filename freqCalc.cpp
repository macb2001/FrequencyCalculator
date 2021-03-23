//Frequency Calculator Program
//Mackenzie Broughton
//March 6, 2020
//this program lets a user input a sentence and then calculates the frequency of words and letters.

#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <array>
#include <cctype>
#include <map>

using namespace std;

typedef map<string, int> sentence;
typedef pair<string, int> senPair;
typedef map<char, int> letter;
typedef pair<char, int> letPair;

char toLower(char);
bool sortByFreq1(const senPair&, const senPair&);
bool sortByWord(const senPair&, const senPair&);
bool sortByFreq2(const letPair&, const letPair&);
bool sortByLetter(const letPair&, const letPair&);
vector<senPair> mapToVector1(sentence, vector<senPair>);
vector<letPair> mapToVector2(letter, vector<letPair>);
void print1(vector<senPair>);
void print2(vector<senPair>);
void print3(vector<letPair>);
void print4(vector<letPair>);
void getSentence(sentence&, letter&);

bool sortByFreq1(const senPair& i, const senPair& j){
	return (i.second > j.second);
}

bool sortByWord(const senPair& i, const senPair& j){
   return (i.first < j.first);
}

bool sortByFreq2(const letPair& i, const letPair& j){
	return (i.second > j.second);
}

bool sortByLetter(const letPair& i, const letPair& j){
   return (i.first < j.first);
}

char toLower(char c){
	return tolower(c);
}

void print1(vector<senPair> V){
   cout << left << setw(15) << "Words" <<
   left << setw(15) << "Frequency" << endl;
   cout << "------------------------------" << endl;

   for(vector<senPair>::iterator it = V.begin(); it != V.end(); it++){
		cout << left << setw(15) << it -> first <<
      left << setw(15) << it -> second << endl;
	}
   cout << endl;
}

void print2(vector<senPair> V){
   cout << left << setw(15) << "Frequency" <<
   left << setw(15) << "Words" << endl;
   cout << "------------------------------" << endl;

   for(vector<senPair>::iterator it = V.begin(); it != V.end(); it++){
		cout << left << setw(15) << it -> second <<
      left << setw(15) << it -> first << endl;
	}
   cout << endl;
}

void print4(vector<letPair> L){
   cout << left << setw(15) << "Letters" <<
   left << setw(15) << "Frequency" << endl;
   cout << "------------------------------" << endl;

   for(vector<letPair>::iterator it = L.begin(); it != L.end(); it++){
		cout << left << setw(15) << it -> first <<
      left << setw(15) << it -> second << endl;
	}
   cout << endl;
}

void print3(vector<letPair> L){
   cout << left << setw(15) << "Frequency" <<
   left << setw(15) << "Letters" << endl;
   cout << "------------------------------" << endl;

   for(vector<letPair>::iterator it = L.begin(); it != L.end(); it++){
		cout << left << setw(15) << it -> second <<
      left << setw(15) << it -> first << endl;
	}
   cout << endl;
}

vector<senPair> mapToVector1(sentence senMap, vector<senPair> V){
   for(sentence::const_iterator it = senMap.begin(); it != senMap.end(); it++){
		V.push_back(make_pair(it -> first, it -> second));
	}
   return V;
}

vector<letPair> mapToVector2(letter letMap, vector<letPair> L){
   for(letter::const_iterator it = letMap.begin(); it != letMap.end(); it++){
		L.push_back(make_pair(it -> first, it -> second));
	}
   return L;
}

void getSentence(sentence& senMap, letter &letMap){
    string word;
    cout << "Input a sentence: " << "\n>> ";
    while(cin >> word){
      transform(word.begin(), word.end(), word.begin(), toLower);
      senMap[word]++;
      
      for(unsigned int i = 0; i < word.length(); i++){
         letMap[word[i]]++;
      }
   }
}

int main(){
	vector<senPair> V;
   vector<letPair> L;
	sentence senMap;
   letter letMap;

   getSentence(senMap, letMap);
	
	V = mapToVector1(senMap, V);
   L = mapToVector2(letMap, L);

	//sort by frequency
   cout << "\nWords sorted by frequency:" << endl;
	sort(V.begin(), V.end(), sortByFreq1);
   print2(V);

	//sort by word
   cout << "Words sorted alphabetically:" << endl;
	sort(V.begin(), V.end(), sortByWord);
   print1(V);

   //sort letters by frequency
   cout << "Letters sorted by frequency:" << endl;
   sort(L.begin(), L.end(), sortByFreq2);
   print3(L);

   //sort letters by letter
   cout << "Letters sorted alphabetically:" << endl;
   sort(L.begin(), L.end(), sortByLetter);
   print4(L);

   return 0;
}