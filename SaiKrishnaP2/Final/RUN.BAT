:run.bat

cd Project2/debug 


@echo OFF
@echo:
echo Input is given in a .xml file
Executive.exe LectureNote.xml 

@echo:
echo Input is given in a .txt file that is read as a string
Executive.exe example.txt

@echo:
echo .xml written file cam be found at location "../Project2/Debug/"

cd ../..