#include "html-parser.hpp"
#include <fstream>
#include <string>
#include <stack>
#include <iostream>
#include <istream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// constructor (initialize)
HTMLParser::HTMLParser() {
    mLinkPos = 0; 
    position = 0;
    mStart = 0; 
    mEnd = 0; 
    count = 0; 
    mLinkTemp = 0; 
    mLink = 0; 
    linkEnd = 0; 
}

// free memory (deallocate)
HTMLParser::~HTMLParser() {
    //bTag.clear();
    //aTag.clear();
    //eTag.clear();
    start.clear();
    end.clear();
    link.clear();
    endLink.clear();
    numLink.clear(); 
    numSTag.clear(); 
    numETag.clear();
    numLinks.clear();
    visited.clear();
    knowName.clear(); 
}

// checks if balanced
bool HTMLParser::isBalanced(std::string filename) {
   int temp = 1;
   // vectors to keep track of beginning and end tags
   std::vector<std::string> newStart;
   std::vector<std::string> newEnd;
   for(int i = 0; i < knowName.size(); i++){
	if(knowName.at(i) == filename){
	   position = i;
	}
   }
   if(position == 0){
       for(int j = 0; j < numSTag.at(position); j++){
	    newStart.push_back(start.at(j));
       }
       for(int j = 0; j < numETag.at(position); j++){
	   newEnd.push_back(end.at(j));	   
       }
   }
   else{
	for(int j = numSTag.at(position - 1); j < numSTag.at(position); j++){
	    newStart.push_back(start.at(j));
	}
	for(int j = numETag.at(position - 1); j < numETag.at(position); j++){
	    newEnd.push_back(end.at(j));
	}
   }
   // compares the vectors if they are the same size
   if(newStart.size() != newEnd.size()){
	return false;
   }
   else{
	for (int j = 0; j < newStart.size(); j++){
	    if(newStart.at(j) != newEnd.at(newEnd.size() - temp)){
		return false;
	    }
	    temp++;
	}
   }
   // here, we check if the tags have end tag
   if(position == 0){
       if(numLink.at(position) != numLinks.at(position)){
	  return false;
       }
   }
   else{
       int sLinkNum = numLink.at(position) - numLink.at(position - 1);
       int eLinkNum = numLinks.at(position) - numLinks.at(position - 1);
       if(sLinkNum != eLinkNum){
	   return false;
       }
   }
   return true;
   //return false;	
}

// parse through 
void  HTMLParser::parse(std::string filename) {
   // stream the file
    std::ifstream input(filename);
    // characters represent the tags' elements
    char ch;
    knowName.push_back(filename);
    // open the file
    while(input.get(ch)){
	// declaration of string
	std::string tempString;
	// starts with the beginning
	if(ch == '<'){
	    // seeks out the anchor tag
	    if(input.peek() == 'a'){
		while(ch != '='){
		    input.get(ch);
		}
		input.get(ch);
		// HERE, we get to the end of the HTML Tag
		while(ch != '>'){
		    tempString += ch;
		    input.get(ch);
		}
		link.push_back(tempString);
		std::string lStr;
		// if not <, not a HTML tag
		while(ch != '<'){
		    input.get(ch);
		}
		// checks the end tag
		if(input.peek() == '/'){
		    input.get(ch);
		    if(input.peek() == 'a'){
			while(ch != '>'){
			    lStr += ch;
			    input.get(ch);
			}
			endLink.push_back(lStr);
			linkEnd++;
		    }
		    else{
			while(ch != '>'){
			    input.get(ch);
			    lStr += ch;
			}
			end.push_back(lStr);
			mEnd++;
		    }
		}
		mLink++;
	    }
	    // this is for the regular anchor end tags
	    else if(input.peek() == '/'){
		input.get(ch);
		if(input.peek() == 'a'){
		    while(ch != '>'){
			input.get(ch);
		    }
		}
		else{
		    while(ch != '>'){
			input.get(ch);
			tempString += ch;
		    }
		    end.push_back(tempString);
		    mEnd++;
		}
	    }
	    // normal tag
	    else{
		while(ch != '>'){
		    input.get(ch);
		    tempString += ch;
		}
		start.push_back(tempString);
		mStart++;
	    }
	}
    }
    numSTag.push_back(mStart);
    numETag.push_back(mEnd);
    numLink.push_back(mLink);
    numLinks.push_back(linkEnd);

    input.close();
}
    // read text from file
    //std::ifstream input(filename);
    //generic holder for characters;
    //char ch;
    // creates a text string, tis inside the angle brackets
    //std::string myText = "";
    // creates a tag string, this is the tags
    //std::string tagMe = "";
    // counter to hold a truth
    //bool pointer = false;
    // we push things onto the stack
    //if(input.is_open()){
	//while(!input.eof()){
	   /* if(ch == '<'){
	        // check for the slash and get ready to pop	    
	        if(input.peek() == '/'){
		    getline(input, myText); // do i need to include >?
		    eTag.push(myText);
                }
	        // anchor tag check
	        else if(input.peek() == 'a'){
		    getline(input, myText);
		    aTag.push(myText);
	        }
	        // all other text after <
	        else{
		    getline(input, myText);
		    bTag.push(myText);
	        }
  	    }*/
    	   /* getline(input, myText);
	    for(int i = 0; i < myText.size(); i++){
		if(myText[i] == '<'){
		    pointer = true;
		}
		else if(myText[i] == '>'){
		    pointer = false;
		    tagMe += '>';
		    tagStack.push(tagMe);
		    tagMe = "";
		}
		if(pointer){
                    tagMe += myText[i];
		}
	    }
        }
    }
    input.close();*/
//}

    // we now start popping things off of the stack and compare recent push
    /*if(eTag.empty() || aTag.empty() || bTag.empty()){
	return false;
    }
    while(input.get(ch)){
	if(input.peek() == '>'){
	    aTag.pop();
	}
	if(input.peek() == '/'){
	    eTag.pop();
	}
    }
    input.close();*/

    /*std::string str = "<html>";
    std::string str2 = "<body>";
    std::string str3 = "<b>";
    std::string str4 = "<a>";
  
    char* h = const_cast<char*>(str.c_str());
    char* b = const_cast<char*>(str2.c_str());
    char* p = const_cast<char*>(str3.c_str());
    char* a = const_cast<char*>(str4.c_str());
    
    while(input.get(ch)){*/

    //iterate the file
    /*for(int i = 0; i < filename.length(); i++){
	if(filename[i] == 'c' || filename[i] == 'b' || filename[i] == 'p'
	     || filename[i] == 'a'){
		tags.push(filename[i]);
	}
	if(tags.empty()){
	    return false;
	}
	switch(filename[i]){
	    case 'h':
		ch = tags.top();
		tags.pop();
		if(ch == 'a' || ch == 'p' || ch == 'b'){
		    return false;
		    break;
		}
	    case 'b':
		ch = tags.top();
		tags.pop();
		if(ch == 'a' || ch == 'p' || ch == 'h'){
		    return false;
		    break;
		}
	    case 'p':
		ch = tags.top();
		tags.pop();
		if(ch == 'a' || ch == 'b' || ch == 'h'){
		    return false;
		    break;
		}
	    case 'a':
		ch = tags.top();
		tags.pop();
		if(ch == 'b' || ch == 'h' || ch == 'p'){
		    return false;
		    break;
		}

	}

    }
   
    return (tags.empty());*/


// recursion
int HTMLParser::pageVisitAmount(std::string filename) {
    count = 0;
    visited.clear();
    return pageHelp(filename);
}
int HTMLParser::pageHelp(std::string filename){
    bool lExists = false;
    bool cExists = false;
    int begPos;
    int size = 0;

    for(int i = 0; i < knowName.size(); i++){
	if(knowName.at(i) == filename){
	    mLinkPos = i;
	    cExists = true;
	}
    }
    if(cExists = false){
	return count; // already initialized to 0
    }
    // for files that already have been 
    for(int k = 0; k < visited.size(); k++){
	if(visited.at(k) == filename){
	    return count;
	}
    }
    // keeps track of visited file
    visited.push_back(filename);

    // balancing base case
    if(!isBalanced(filename)){
	return count;
    }
    // finds number of links within the file
    if(mLinkPos == 0){
	size = numLink.at(mLinkPos);
	if(size != 0){
	    begPos = 0;
	    for(int k = begPos; k < (begPos + size); k++){
		for(int j = 0; j < knowName.size(); j++){
		    if(link.at(k) == knowName.at(j)){
			lExists = true;
			//startPos++;
		    }
		}
		// increment the amt of pages a page can visit
		if(lExists == true){
		    count += 1;
		    pageHelp(link.at(k));
		}
		lExists = false;
	    }
	}
    }
    else{
	size = (numLink.at(mLinkPos) - numLink.at(mLinkPos - 1));
	if(size != 0){
	    begPos = numLink.at(mLinkPos) - size;
	    for(int k = begPos; k < (begPos + size); k++){
		for(int j = 0; j < knowName.size(); j++){
	 	    if(link.at(k) == knowName.at(j)){
			lExists = true;
		    }
		}
		if(lExists = true){
		    count += 1;
		    pageHelp(link.at(k));
		}
		lExists = false;
	     } 
	 }
    }
    return count;
}
