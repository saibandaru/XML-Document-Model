///////////////////////////////////////////////////////////////////
// TestDemo.cpp - To Demonstrate the requirements acse wise      //
// ver 1.0                                                       //
// Application:  Demonstrate the requirements of Project 2	     //
// Platform:    Dell XPS 2720, Win 8.1 Pro, Visual Studio 2013   //
// Author:      Sai Krishna, 8329408083                          //
//              sbandaru@syr.edu                                 //
///////////////////////////////////////////////////////////////////

#include "TestDemo.h"

//----< To search an attribute >---------------------------------------
void TestDemo::SearchAttribute(XmlProcessing::XmlDocument &xmldoc, std::string attribute){
	Display::display_title("Searching for attribute \"" + attribute + "\"");
	Display::display_attrSearch(xmldoc.attrsearch(attribute));
}

//----< To search an element >---------------------------------------
void TestDemo::SearchElement(XmlProcessing::XmlDocument &xmldoc, std::string tag){
	Display::display_title("Searching for tag \"" + tag + "\"");
	Display::display_selectEle(xmldoc.elements(tag).select());
}

//----< To add a child >---------------------------------------
void TestDemo::AddChild(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string child){
	Display::display_title("Trying to add \"" + child + "\" to parent \"" + parent + "\"");
	Display::display_addOrRemove(xmldoc.addChildDoc(parent, child));
}

//----< To delete a child >---------------------------------------
void TestDemo::DeleteChild(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string child){
	Display::display_title("Trying to delete \"" + child + "\" of parent \"" + parent + "\"");
	Display::display_addOrRemove(xmldoc.removeChildDoc(parent, child));
}

//----< To add root element >---------------------------------------
void TestDemo::AddRoot(XmlProcessing::XmlDocument &xmldoc, std::string root){
	Display::display_title("Trying to add root \"" + root + "\" to a document element ");
	Display::display_addOrRemove(xmldoc.addRoot(root));
}

//----< To fetch the attributes >---------------------------------------
void TestDemo::FetchAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag){
	Display::display_title("Trying to fetch attribute value pair for tag \"" + tag + "\"");
	Display::display_attribute(xmldoc.getAttributes(tag));
}

//----< To fetch children >---------------------------------------
void TestDemo::FetchChildren(XmlProcessing::XmlDocument &xmldoc, std::string parent){
	Display::display_title("Fetching the children information for element \"" + parent + "\"");
	Display::display_children(xmldoc.elements(parent).allChildren().select());
}

//----< To add attributes >---------------------------------------
void TestDemo::AddAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag, std::string attribute, std::string value){
	Display::display_title("Adding attribute (" + attribute + "," + value + ") to tag \"" + tag + "\"");
	Display::display_addOrRemove(xmldoc.addAttribute(tag, attribute, value));
}

//----< To remove attributes >---------------------------------------
void TestDemo::RemoveAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag, std::string attribute){
	Display::display_title("Trying to remove attribute \"" + attribute + "\" from tag \"" + tag + "\"");
	Display::display_addOrRemove(xmldoc.removeAttribute(tag, attribute));
}

//----< To write into text file >---------------------------------------
void TestDemo::WriteToFile(XmlProcessing::XmlDocument &xmldoc, std::string filename){
	Display::display_text("****Demonstrating Requirement 3:Implementing move constructor and move assignment  ");
	Display::display_title("Move Operations");
	XmlProcessing::XmlDocument xmldoc1 = std::move(xmldoc);
	XmlProcessing::XmlDocument xmldoc2;
	xmldoc2 = std::move(xmldoc1);
	std::cout << "\n-------------------------End ---------------------------------------------\n";
	Display::display_text("****Demonstrating Requirement 10:Writing the contents of XmlDocument into file  ");
	Display::display_title("Trying to write XML tree into file \"" + filename + "\"");
	Display::display_addOrRemove(xmldoc2.writeToFile(filename));
}

//----< To display Descendents  >---------------------------------------
void TestDemo::ForDescendents(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string tag){
	Display::display_title("Searching for Descendents for \"" + tag + "\" which is under parent " + parent);
	Display::display_selectDesc(xmldoc.elements(parent).descendents(tag).select());
}

//----< test stub >----------------------------------------------------------
#ifdef TEST_TESTDEMO

int main(int argc, char* argv[])
{
	XmlProcessing::XmlDocument xmldoc;
	xmldoc.BuildTree(xmldoc.parse(argv[1],true));
	std::string tag = "LectureNote", child = "<type></type>", parent = "reference", root = "<LectureNote2>", 
		value = "123456", filename = "Examlpe_write.txt", attribute = "course";
	Display::display_tree(xmldoc);
	TestDemo::SearchAttribute(xmldoc, attribute);
	TestDemo::SearchElement(xmldoc, tag);
	TestDemo::AddChild(xmldoc, parent, child);
	TestDemo::DeleteChild(xmldoc, parent, child);
	XmlProcessing::XmlDocument xmldoc2;
	TestDemo::AddRoot(xmldoc2, root);
	TestDemo::FetchAttribute(xmldoc, tag);
	TestDemo::FetchChildren(xmldoc, parent);
	TestDemo::AddAttribute(xmldoc, tag, attribute, value);
	TestDemo::RemoveAttribute(xmldoc, tag, attribute);
	TestDemo::WriteToFile(xmldoc, filename);
	TestDemo::ForDescendents(xmldoc, parent, tag); return 1;
}

#endif