#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &core = project.static_library("core");

  core.sources("core/src/message.cpp");
  core.public_include_directory("core/include");

  auto &app = project.executable("app");

  app.sources("app/src/main.cpp");
  app.link(core);
}
