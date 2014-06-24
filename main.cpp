// STD includes
#include <iostream>
#include <string>

#define TCLAP_NAMESTARTSTRING "-"
#define TCLAP_FLAGSTARTSTRING "-"
#include <tclap/CmdLine.h>

// VruiVTK includes
#include "VruiVTK.h"

/* Create and execute an application object: */
/*
 * main - The application main method.
 *
 * parameter argc - int
 * parameter argv - char**
 *
 */
int main(int argc, char* argv[])
{
  try
    {
    TCLAP::CmdLine cmd("Render VTK objects in the VRUI context", ' ', "0.1");
    TCLAP::ValueArg<std::string> fileName("f", "fileName",
      "Name of OBJ file to load using VTK", false, "", "string");
    TCLAP::ValueArg<std::string> rootSection("", "rootSection",
      "Name of section to use as rootSection from Vrui.cfg.", false, "", "string");
    cmd.add(fileName);
    cmd.add(rootSection);
    cmd.parse(argc, argv);

    VruiVTK application(argc, argv);
    std::string name = fileName.getValue();
    if(!name.empty())
      {
      application.setFileName(name.c_str());
      }
    application.run();
    return 0;
    }
  catch (TCLAP::ArgException &e)
    {
    std::cerr << "Error: Exception " << e.error() <<
      " for arg " << e.argId() << std::endl;
    return 1;
    }
}
