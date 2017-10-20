# proCreator
Helper to replicate project-settings for legacy-Qt-projects

# What?
A tool to start with given path to create a valid pro-file for usage with qmake/QtCreator
Content of a given directory is collected and put into headers, sources, forms and ressources. Other files than h, hpp, cpp, qrc and ui are ignored.
By default an "app" is assumed as template. Also the most basic Qt-libraries are included. Targetname is hardcoded.

If you don't like - expand or don't use :)
This is just a small helper for something you can do manually. But it is boring.

# How to use?
- build as via pro-file
- run inside a shell "proCreator /path/to/sourcefiles"
- running with . searches inside the current. is also the default mode without any specification
