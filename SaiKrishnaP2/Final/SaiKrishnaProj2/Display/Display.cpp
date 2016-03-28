///////////////////////////////////////////////////////////////////
// Display.cpp - Display Module Implementation                   //
// ver 1.0                                                       //
// Application: Display Module of Project#2		                 //
// Platform:    Dell XPS 2720, Win 8.1 Pro, Visual Studio 2013   //
// Author:      Sai Krishna, 832-9408083		                 //
//              sbandaru@sye.edu	                             //
///////////////////////////////////////////////////////////////////

#include "Display.h"

using sPtr = std::shared_ptr <XmlProcessing::AbstractXmlElement >;

//----< Display a title string >----------------------------------------
void Display::display_title(std::string text)
{
	std::cout << "===========================================================================\n";
	std::cout << text << "\n";
	std::cout << "===========================================================================\n";
}

//----< Display a title string >----------------------------------------
void Display::display_text(std::string text)
{
	std::cout << "\n" << text << "\n";
}

//----< Display a title string >----------------------------------------
void Display::display_tree(XmlProcessing::XmlDocument& xmldoc)
{
	display_title("Abstract Syntax Tree Structure");
	std::cout << xmldoc.display();
	std::cout << "\n\n-------------------------End ---------------------------------------------\n";
}

//----< Display a title string >----------------------------------------
void Display::display_attrSearch(std::shared_ptr < XmlProcessing::AbstractXmlElement > element)
{
	if (element != NULL){
		std::cout << "\nFound in Element:\n";
		std::cout << "  " << element->value() << "\n";
	}
	std::cout << "\n-------------------------End ---------------------------------------------\n";
}

//----< Display a title string >----------------------------------------
void Display::display_selectEle(std::vector<std::shared_ptr < XmlProcessing::AbstractXmlElement >> result)
{
	if (result.size())
	{
		std::cout << "\nThe tag \"" << result[0]->value() << "\" is found in " << (result.size()) << " location(s)\n";
	}
	std::cout << "\n-------------------------End ---------------------------------------------\n";
}

//----< Display a title string >----------------------------------------
void Display::display_addOrRemove(bool result)
{
	if (result == true)
		std::cout << "\nOperation is successful";
	else
		std::cout << "\nOperation has failed";
	std::cout << "\n-------------------------End ---------------------------------------------\n";
}

//----< Display a title string >----------------------------------------
void Display::display_attribute(std::vector<std::pair<std::string, std::string>> attributes)
{
	if (!attributes.size())Display::display_text("No attributes");
	else{
		std::cout << "(Attribute,value) pairs are:\n\n";
		for (auto itr_att : attributes)
			std::cout << "(" << itr_att.first << "," << itr_att.second << ")\n";
	}
	std::cout << "\n-------------------------End ---------------------------------------------\n";
}

//----< Display a title string >----------------------------------------
void Display::display_children(std::vector<sPtr> tags)
{
	if (tags.size())
	{
		std::cout << "\nGiven Tag has children:\n";
		for (auto itr_tag : tags)
			std::cout << "  " << itr_tag->value() << "\n";
	}
	else std::cout << "\nHas no children\n";
	std::cout << "\n-------------------------End ---------------------------------------------\n";
}
void Display::display_selectDesc(std::vector<std::shared_ptr < XmlProcessing::AbstractXmlElement >> result)
{
	if (!result.size()){
		Display::display_text("There are no Descendents");
	}
	else{
		Display::display_text("Descendents");
		for (auto itr_ele : result)
			std::cout << "   " << itr_ele->value() << "\n";
	}
	std::cout << "\n-------------------------End ---------------------------------------------\n";
}

//----< test stub >----------------------------------------------------------

#ifdef TEST_DISPLAY

int main()
{
	Display::display_text("Testing text");
	Display::display_title("Texting title");
	return 1;
}

#endif