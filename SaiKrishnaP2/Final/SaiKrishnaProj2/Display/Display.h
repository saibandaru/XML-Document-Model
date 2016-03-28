#ifndef DISPLAY_H
#define DISPLAY_H
///////////////////////////////////////////////////////////////////
// Display.h - Display Module			                         //
// ver 1.0                                                       //
// Application: Display Module of Project#2		                 //
// Platform:    Dell XPS 2720, Win 8.1 Pro, Visual Studio 2013   //
// Author:      Sai Krishna, 832-9408083		                 //
//              sbandaru@sye.edu	                             //
///////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package is display the output to the console ina proper,clear and easy to understand format 
* Public Interface:
* =================
*display_title(std::string );									Display a title string
*
*display_text(std::string );									Display a text string
*
*display_tree(XmlProcessing::XmlDocument );						Print the tree to console
*
*display_attrSearch(std::shared_ptr < XmlProcessing::AbstractXmlElement >);					Print the tags for selected attribute
*
*display_selectEle(std::vector<std::shared_ptr < XmlProcessing::AbstractXmlElement >> );	Print the tags for selected tag
*
*display_addOrRemove(bool result);								Print the result of given operation
*
*display_attribute(std::vector<std::pair<std::string, std::string>> );						Print the found attributes
*
*display_children(std::vector<sPtr> tags);						Print the found children
*
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
#include <vector>
#include <string>
#include "../XmlElement/XmlElement.h"
#include "../XmlDocument/XmlDocument.h"

class Display
{
public:
	using sPtr = std::shared_ptr <XmlProcessing::AbstractXmlElement >;
	static void display_title(std::string );									//Display a title string
	static void display_text(std::string );										//Display a text string
	static void display_tree(XmlProcessing::XmlDocument &);						//Print the tree to console
	static void display_attrSearch(std::shared_ptr < XmlProcessing::AbstractXmlElement >);	//Print the tags for selected attribute
	static void display_selectEle(std::vector<std::shared_ptr < XmlProcessing::AbstractXmlElement >> );	//Print the no of tags for selected tag
	static void display_addOrRemove(bool result);								//Print the result of given operation
	static void display_attribute(std::vector<std::pair<std::string, std::string>> attributes);	//Print the found attributes
	static void display_children(std::vector<sPtr> tags);						//Print the found children
	static void display_selectDesc(std::vector<std::shared_ptr < XmlProcessing::AbstractXmlElement >> );//Print the tags for selected tag decendents

};
#endif
