// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Translation
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "world/world.h"
#include "renderer/console/console_material.h"
#include "model/model.h"
#include "camera/linear_camera.h"
#include "renderer/console/console_renderer.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(World, TestEnvironment)

/**
 * Tests the construction and destruction of World.
 */
BOOST_AUTO_TEST_CASE(TestWorldConstruction)
{
    CE3D::World<CE3D::ConsoleMaterial> TestWorld;
}

BOOST_AUTO_TEST_CASE(TestRenderer)
{
    // Create vector
    Vector AVec(3);
    // x position
    AVec(0)=2;
    // y position
    AVec(1)=3;
    // z position
    AVec(2)=0;

    // Create vertex
    Vertex<CE3D::ConsoleMaterial> TestVertex;
    // THIS DOESNT WORK YET
    CE3D::ConsoleMaterial Mat(ConsoleColor::RED);
    TestVertex.SetMaterial(Mat);
    TestVertex.GetVectors().push_back(0);

    // Create model
    std::shared_ptr<CE3D::Model<CE3D::ConsoleMaterial> >
    TestModel(new CE3D::Model<CE3D::ConsoleMaterial>());
    TestModel->SetName("TestModel");
    TestModel->GetVectors().push_back(AVec);
    TestModel->GetVertices().push_back(TestVertex);

    // Create world
    std::shared_ptr<CE3D::World<CE3D::ConsoleMaterial> >
    TestWorld(new CE3D::World<CE3D::ConsoleMaterial>);
    TestWorld->AddModel(TestModel);

    // Create camera
    CE3D::LinearCamera<ConsoleMaterial> TestCamera;
    TestCamera.SetWorld(TestWorld);

    // Render it
    CE3D::ConsoleRenderer Renderer;
    Renderer.Render(TestCamera);

    //while(1);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
