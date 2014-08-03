// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OrthographicCamera
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"
#include "CE3D/test/testutilities.h"

#include <vector>

#include "CE3D/camera/orthographic_camera.h"
#include "CE3D/renderer/console/console_renderer.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(OrthographicCamera, TestEnvironment)

/**
 * Tests the construction of and destruction of OrthographicCamera.
 */
BOOST_AUTO_TEST_CASE(TestOrthographicCameraConstruction)
{
    CE3D::OrthographicCamera<CE3D::ConsoleMaterial> *TestUnit;
    BOOST_REQUIRE_NO_THROW(
        TestUnit = new CE3D::OrthographicCamera<CE3D::ConsoleMaterial>
        (CE3D::Vector(), CE3D::Vector()));
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

/**
 * Tests the getter and setter functions of OrthographicCamera.
 */
BOOST_AUTO_TEST_CASE(TestPropertyFunctions)
{
    CE3D::OrthographicCamera<CE3D::ConsoleMaterial> cam
        ((CE3D::Vector()), (CE3D::Vector()));

    CE3D::Vector testvector(5);
    testvector(0) = 17;
    testvector(1) = 1;
    testvector(2) = 3;
    testvector(3) = 100;
    testvector(4) = 121;
   
    cam.SetLookAt(testvector);

    RequireVectorEquality(cam.GetLookAt(), testvector);

    CE3D::Vector testvector2(5);
    testvector2(0) = 1.5;
    testvector2(1) = 55;
    testvector2(2) = 7.4;
    testvector2(3) = 33.333;
    testvector2(4) = 1003012;

    cam.SetPosition(testvector2);

    RequireVectorEquality(cam.GetPosition(), testvector2);
}

/**
 * Tests the matrix result of OrthographicCamera.
 */
BOOST_AUTO_TEST_CASE(TestMatrix)
{
    CE3D::OrthographicCamera<CE3D::ConsoleMaterial> cam
        ((CE3D::Vector()), (CE3D::Vector()));

    std::shared_ptr<CE3D::World<CE3D::ConsoleMaterial>> 
        world(new CE3D::World<CE3D::ConsoleMaterial>());
    std::shared_ptr<CE3D::Model<CE3D::ConsoleMaterial>>
        model(new CE3D::Model<CE3D::ConsoleMaterial>());
    
    std::vector<Vector> vectors;
    CE3D::Vector testvector(4);
    testvector(0) = 1;
    testvector(1) = 1;
    testvector(2) = 1;
    testvector(3) = 1;
    vectors.push_back(testvector);
    testvector(0) = 1;
    testvector(1) = 2;
    testvector(2) = 3;
    testvector(3) = 1;
    vectors.push_back(testvector);
    testvector(0) = 7;
    testvector(1) = 11;
    testvector(2) = 20;
    testvector(3) = 1;
    vectors.push_back(testvector);
 
    for (auto elem : vectors)
        model->GetVectors().push_back(elem);

    world->AddModel(model);

    cam.SetWorld(world);

    CE3D::Vector translationvector(3);
    translationvector(0) = 1;
    translationvector(1) = 2;
    translationvector(2) = 3;
    
    CE3D::Vector lookatvector(3);
    lookatvector(0) = 4;
    lookatvector(1) = 6;
    lookatvector(2) = 6;

    CE3D::Transformation::FinalTranslation translation(-translationvector);
    cam.SetPosition(translationvector);

    CE3D::Transformation::OrthogonalDepthProjection projection;
    projection.SetProjectionVectors(lookatvector);
    cam.SetLookAt(lookatvector);

    CE3D::Matrix testmatrix(3, 4);
    boost::numeric::ublas::axpy_prod(
        projection.GetMatrix(), translation.GetMatrix(), testmatrix, true);

    
    auto transformed_world = cam.Paint();

    for (unsigned int i = 0; i < vectors.size(); i++)
    {
        CE3D::Vector refvector(3);
        boost::numeric::ublas::axpy_prod(
            testmatrix, vectors[i], refvector, true);
        
        RequireVectorEquality(transformed_world->GetModels()[0]->
            GetVectors()[i], refvector);
    }

}

BOOST_AUTO_TEST_SUITE_END()

}
}
