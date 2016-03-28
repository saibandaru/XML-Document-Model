#ifndef TESTDEMO_H
#define TESTDEMO_H
///////////////////////////////////////////////////////////////////
// TestDemo.h   - To Demonstrate the requirements acse wise      //
// ver 1.0                                                       //
// Application:  Demonstrate the requirements of Project 2	     //
// Platform:    Dell XPS 2720, Win 8.1 Pro, Visual Studio 2013   //
// Author:      Sai Krishna, 8329408083                          //
//              sbandaru@syr.edu                                 //
///////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package is used to demosntrate each case of Project 2 by displaying to  the console ina proper,clear and easy to understand format
* Public Interface:
* =================
*< To search an attribute >		 SearchAttribute(XmlProcessing::XmlDocument &xmldoc, std::string attribute)
*
*< To search an element >		 SearchElement(XmlProcessing::XmlDocument &xmldoc, std::string tag)
*
*< To add a child >				 AddChild(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string child)
*
*< To delete a child >			DeleteChild(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string child)
*
* To add root element >			AddRoot(XmlProcessing::XmlDocument &xmldoc, std::string root)
*
*< To fetch the attributes >	FetchAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag)
*
*< To fetch children >			FetchChildren(XmlProcessing::XmlDocument &xmldoc, std::string parent)
*
*< To add attributes >			AddAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag, std::string attribute, std::string value)
*
*< To remove attributes >		RemoveAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag, std::string attribute)
*
*< To write into text file >	WriteToFile(XmlProcessing::XmlDocument &xmldoc, std::string filename)
*
*< To display Descendents  >	ForDescendents(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string tag)
* Required Files:
* ---------------
*   - XmlElement.h, XmlElement.cpp , XmlDocument.cpp. XmlDocument.h, Display.h, Display.cpp, Tokenizer.h, xmlElementParts.h
*
* Build Process:
* --------------
*   devenv XmlDocument.sln /debug rebuild
*
* Maintenance History:
* --------------------
* - first release 21st March 2015
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

#include "../Display/Display.h"
#include "../XmlElement/XmlElement.h"
#include "../FileSystem/FileSystem.h"
#include "../XmlDocument/XmlDocument.h"
class TestDemo
{
public:													//functions to implement requirements
	static void SearchAttribute(XmlProcessing::XmlDocument &xmldoc, std::string attribute);
	static void SearchElement(XmlProcessing::XmlDocument &xmldoc, std::string tag);
	static void AddChild(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string child);
	static void DeleteChild(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string child);
	static void AddRoot(XmlProcessing::XmlDocument &xmldoc, std::string root);
	static void FetchAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag);
	static void FetchChildren(XmlProcessing::XmlDocument &xmldoc, std::string parent);
	static void AddAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag, std::string attribute, std::string value);
	static void RemoveAttribute(XmlProcessing::XmlDocument &xmldoc, std::string tag, std::string attribute);
	static void WriteToFile(XmlProcessing::XmlDocument &xmldoc, std::string filename);
	static void ForDescendents(XmlProcessing::XmlDocument &xmldoc, std::string parent, std::string tag);
};

#endif