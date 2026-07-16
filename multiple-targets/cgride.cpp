#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &server = project.executable("server");

  server.sources("server/src/main.cpp");

  auto &worker = project.executable("worker");

  worker.sources("worker/src/main.cpp");
}
