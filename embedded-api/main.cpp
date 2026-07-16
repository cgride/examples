#include <cgride/cgride.hpp>

#include <filesystem>
#include <iostream>
#include <utility>

int main()
{
  cgride::project::Project project;

  auto &app = project.executable("embedded_hello");

  app.sources("src/main.cpp");

  auto toolchain = cgride::toolchains::discover_toolchain(
      cgride::toolchains::CompilerKind::Unknown);

  if (!toolchain)
  {
    std::cerr << "Failed to discover a C++ toolchain\n";
    return 1;
  }

  cgride::engine::BuildOptions options;

  options
      .build_directory(std::filesystem::path(".cgride") / "embedded-api-build")
      .mode(cgride::engine::BuildMode::Debug)
      .dry_run(true)
      .verbose(true);

  cgride::engine::BuildRequest request;

  request
      .project(std::move(project))
      .toolchain(std::move(toolchain.value()))
      .options(options);

  cgride::engine::BuildEngine engine;

  auto result = engine.build(request);

  if (result.failed())
  {
    std::cerr << "Cgride embedded build request failed\n";

    if (result.error().has_value())
    {
      std::cerr << result.error().value().message() << '\n';
    }

    return 1;
  }

  std::cout << "Cgride embedded API example completed\n";
  return 0;
}
