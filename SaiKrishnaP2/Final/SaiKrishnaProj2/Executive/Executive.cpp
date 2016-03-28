///////////////////////////////////////////////////////////////////
// Executive.cpp -The head module which calls the functions      //
// ver 1.0                                                       //
// Application: Executive Module of Project#2	                 //
// Platform:    Dell XPS 2720, Win 8.1 Pro, Visual Studio 2013   //
// Author:      Sai Krishna, 832-9408083		                 //
//              sbandaru@sye.edu	                             //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

#include "../Display/Display.h"
#include "../XmlElement/XmlElement.h"
#include "../FileSystem/FileSystem.h"
#include "../XmlDocument/XmlDocument.h"
#include "../XML Paresr/XmlElementParts/xmlElementParts.h"
#include "../XML Paresr/XmlElementParts/itokcollection.h"
#include "../XML Paresr/XmlElementParts/Tokenizer.h"
#include "../TestDemo/TestDemo.h"

#ifdef TEST_EXECUTIVE
void callAllCases(XmlProcessing::XmlDocument& xmldoc);

//----< Execution starts from here main() >----------------------------------------
int main(int argc, char* argv[])
{
	std::string input_string;std::vector<std::string> parsed;
	XmlProcessing::XmlDocument xmldoc;								//parsing command line
	if (argc < 2)
	{
		Display::display_text("please provide file extension with .xml or .txt in command line");return 1;
	}
	else
	{
		std::string filename = argv[1], sub_string, temp;
		std::stringstream stream(filename);
		std::getline(stream, sub_string, '.'); std::getline(stream, sub_string, '.');
		if (sub_string == "txt")
		{
			std::ifstream infile;
			infile.open(filename);
			while (!infile.eof())								 // To get you all the lines.
			{
				std::getline(infile, temp);						 // Saves the line in STRING.
				input_string.append(temp);						// Prints our STRING.
			}
				if (input_string.size())
				parsed = xmldoc.parse(input_string, false);
				else{
					Display::display_text("input string is incorrect");return 1;
				}
		}
		else if (sub_string == "xml")parsed=xmldoc.parse(argv[1], true);
	}
	xmldoc.BuildTree(parsed);
	 
	callAllCases(xmldoc);						//test cases are defined here
	return 1;
}

//----< Implements all the test cases >----------------------------------------
void callAllCases(XmlProcessing::XmlDocument& xmldoc)      //calling all the cases defined in TestDemo class
{
	std::string tag = "LectureNote", child = "<type></type>", delete_child = "date", parent = "reference", root = "<LectureNote2></LectureNote2>",
		value = "123456", filename = "Examlpe_write.xml", attribute = "course", attribute_addDelete = "added";
	Display::display_text("****Demonstrating Requirement 3:Abstract Syntax Tree "); Display::display_tree(xmldoc);
	Display::display_text("****Demonstrating Requirement 5:Search Attribute "); TestDemo::SearchAttribute(xmldoc, attribute); TestDemo::SearchAttribute(xmldoc, "***");
	tag = "date";
	Display::display_text("****Demonstrating Requirement 6:Search for Element with Tag  "); TestDemo::SearchElement(xmldoc, tag); TestDemo::SearchElement(xmldoc, "***");
	Display::display_text("****Demonstrating Requirement 7(a):Adding a child to given tag  "); TestDemo::AddChild(xmldoc, parent, child); TestDemo::AddChild(xmldoc, "***", child);
	Display::display_text("****Demonstrating Requirement 7(b):Deleting a child from given tag  "); TestDemo::DeleteChild(xmldoc, parent, delete_child); TestDemo::DeleteChild(xmldoc, "***", delete_child); TestDemo::DeleteChild(xmldoc, parent, delete_child);
	XmlProcessing::XmlDocument xmldoc2;
	Display::display_text("****Demonstrating Requirement 7(c):Adding root to XMLDocument  "); TestDemo::AddRoot(xmldoc2, root); TestDemo::AddRoot(xmldoc2, root);
	tag = "LectureNote";
	Display::display_text("****Demonstrating Requirement 8(a):Retriving Attribute and value pair of given Tag  "); TestDemo::FetchAttribute(xmldoc, tag); TestDemo::FetchAttribute(xmldoc, "***");
	Display::display_text("****Demonstrating Requirement 8(b):Retriving Children information of given Tag  "); TestDemo::FetchChildren(xmldoc, parent); TestDemo::FetchChildren(xmldoc, "***");
	Display::display_text("****Demonstrating Requirement 9(a):Adding attribute to given Tag  "); TestDemo::AddAttribute(xmldoc, tag, attribute_addDelete, value); TestDemo::AddAttribute(xmldoc, "***", attribute_addDelete, value);
	attribute_addDelete = "course";
	Display::display_text("****Demonstrating Requirement 9(b):Deleting attribute to given Tag  "); TestDemo::RemoveAttribute(xmldoc, "Jeff Prosise", attribute_addDelete); 	 TestDemo::RemoveAttribute(xmldoc, tag, attribute_addDelete); TestDemo::RemoveAttribute(xmldoc, "**", attribute);
	Display::display_text("****Demonstrating Descendents functionality  "); TestDemo::ForDescendents(xmldoc, tag, parent); TestDemo::ForDescendents(xmldoc, parent, "***");
	TestDemo::WriteToFile(xmldoc, filename);
	Display::display_text("Note:Now we cannot access the Xmldocument object created in main() that is passed to WriteToFile() as it has been moved");
}

#endif
