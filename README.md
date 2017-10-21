# proCreator
Helper to replicate project-settings for legacy-Qt-projects

# What?
A tool to start with given path to create a valid pro-file for usage with qmake/QtCreator
Content of a given directory is collected and put into headers, sources, forms and ressources. Other files than h, hpp, cpp, qrc and ui are ignored. Sections with no content (because no fitting file-type was found) are also not created.
By default an "app" is assumed as template. Also the most basic Qt-libraries are included. Targetname is hardcoded.

If you don't like - expand or don't use :)
This is just a small helper for something you can do manually. But it is boring.

# How to use?
- build as via pro-file
- run inside a shell "proCreator /path/to/sourcefiles"
- running with . searches inside the current. is also the default mode without any specification


# open tasks
- DirectoryReader: read the content of the directory; pick the preferred filetypes for headers/sources/forms/ ressources ..
- hand that data over to the ProFileWriter

################ current state of the output ##############

Starting ~/proCreator/proCreator...
##########################################################
# pro-file created by proCreator                         #
#   project: https://github.com/marcelpetrick/proCreator #
#   contact: mail@marcelpetrick.it                       #
##########################################################

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proCreatorProject
TEMPLATE = app

SOURCES += \
	file0.cpp 

HEADERS += \
	file0.h \
	file1.h \
	file2 

~/proCreator/proCreator exited with code 0
