#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &core = project.static_library("core");

  core.sources("core/src/message.cpp");
  core.include_dirs("core/include");

  auto &app = project.executable("app");

  app.sources("app/src/main.cpp");
  app.links(core);
}
