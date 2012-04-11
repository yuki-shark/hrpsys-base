#include <hrpCorba/OpenHRPCommon.hh>
#include <hrpModel/World.h>
#include <hrpModel/ConstraintForceSolver.h>
#include <hrpUtil/TimeMeasure.h>
#include "Project.h"
#include "ProjectUtil.h"

class GLscene;
class BodyRTC;

class Simulator
{
public:
    void init(Project &prj, BodyFactory &factory, GLscene *i_scene);
    bool oneStep();
    void stopSimulation();
    void checkCollision(OpenHRP::CollisionSequence &collisions);

    hrp::World<hrp::ConstraintForceSolver> world;
    GLscene *scene;
private:
    std::vector<BodyRTC *> bodies; 
    std::vector<ClockReceiver> receivers;
    std::vector<hrp::ColdetLinkPairPtr> pairs;
    OpenHRP::WorldState state;
    double totalTime;
    TimeMeasure tm_dynamics, tm_control, tm_collision;
};
