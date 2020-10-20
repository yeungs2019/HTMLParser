#ifndef HTML_PARSER_HPP
#define HTML_PARSER_HPP

#include <string>
#include <stack>
#include <vector>
class HTMLParser {
    public:
        HTMLParser();
        ~HTMLParser();
        void parse(std::string filename);
        bool isBalanced(std::string filename);
        int pageVisitAmount(std::string filename);
	int pageHelp(std::string filename);
    private:
	std::stack<std::string> tagStack;
	//std::stack<std::string> aTag;
	//std::stack<std::string> eTag;
	std::vector<std::string> start;
	std::vector<std::string> end;
	std::vector<std::string> link;
	std::vector<std::string> endLink;
	std::vector<int> numLink;
	std::vector<int> numSTag; 
	std::vector<int> numETag; 
	std::vector<int> numLinks; 
	std::vector<std::string> visited;
	std::vector<std::string> knowName; 
	int mLinkPos; 
	int position; 
	int mStart;
	int mEnd; 
	int count; 
	int mLinkTemp; 
	int mLink;
	int linkEnd;
};

#endif
