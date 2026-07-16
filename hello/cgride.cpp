#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &app = project.executable("hello");

  app.sources("src/main.cpp");
}
