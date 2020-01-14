
#include "igl/opengl/glfw/renderer.h"
#include "tutorial/sandBox/inputManager.h"

int main(int argc, char *argv[])
{
  Display *disp = new Display(1000, 800, "Wellcome");
  Renderer renderer;
  igl::opengl::glfw::Viewer viewer;
  std::ifstream infile("C:/Users/wisam/Desktop/vgp4-master/configuration.txt");
  std::string line;
  while (std::getline(infile, line)) {
	  std::cout << line << std::endl;
	  viewer.load_mesh_from_file(line);
	  std::istringstream iss(line);
  }
  viewer.MyTranslate(Eigen::Vector3f(0, 0, -1));
  for (int i = 0; i < 2; i++) {
	  viewer.selected_data_index = i;
	  renderer.core().toggle(viewer.data().show_lines);
	  viewer.data().buildBox();
	  viewer.data().set_colors(Eigen::RowVector3d(0.8, 0.8, 0));
	  if(i == 0) {
		  viewer.data().MyTranslate(Eigen::Vector3f(-0.5, 0, 0));
	  }
	  else {
		  viewer.data().MyTranslate(Eigen::Vector3f(0.5, 0, 0));
	  }
  }
  viewer.data().set_colors(Eigen::RowVector3d(0.5, 0, 0));
  Init(*disp);
  renderer.init(&viewer);
  disp->SetRenderer(&renderer);
  disp->launch_rendering(true);
  
  delete disp;
}
