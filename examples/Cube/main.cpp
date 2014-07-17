// This file is part of CE3D. License: GPL3

#include <CE3D/renderer/console/console_renderer.h>
#include <CE3D/renderer/console/console_material.h>
#include <CE3D/model/model.h>
#include <CE3D/model/vertex.h>
#include <CE3D/world/world.h>
#include <CE3D/camera/manual_camera.h>
#include <CE3D/util/CE3D_vector.h>

int main(void)
{
    // Create vector
    CE3D::Vector AVec(3);
    // x position
    AVec(0)=2;
    // y position
    AVec(1)=3;
    // z position
    AVec(2)=0;

    // Create vertex
    CE3D::Vertex<CE3D::ConsoleMaterial> TestVertex;
    // COLOR DOESNT WORK YET
    CE3D::ConsoleMaterial Mat(CE3D::ConsoleColor::RED);
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
    CE3D::ManualCamera<CE3D::ConsoleMaterial> TestCamera;
    TestCamera.SetWorld(TestWorld);

    // Render it
    CE3D::ConsoleRenderer Renderer;
    Renderer.Render(TestCamera);

    while(1);

    return 0;
}
