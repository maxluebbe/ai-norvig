#include <gtest/gtest.h>
#include "environment.h"

namespace {
    class EnvironmentTest : public ::testing::Test {
        protected:
            aich2::Room *rooom;// = aich2::Room(1,1);
            aich2::Position robot;
            aich2::Position home;
            aich2::Environment ennv;
            aich2::SensorReading sr;
            void SetUp() override {
                rooom = new aich2::Room(1,1);
                robot = aich2::Position(0, 0, aich2::EAST);
                home = aich2::Position(0, 0, aich2::NORTH);
                ennv = aich2::Environment(rooom, &robot, &home);
            }
            void TearDown() override {
                free(rooom);
            }
    };

    TEST_F(EnvironmentTest, SmokeTest) {
        aich2::Room room = aich2::Room(1,1);
        //aich2::Position robot = aich2::Position(0, 0, aich2::NORTH);
        //aich2::Position home = aich2::Position(0, 0, aich2::NORTH);
        aich2::Environment env = aich2::Environment(&room, &robot, &home);
        //aich2::SensorReading sr;
        env.ReadSensor(&sr);
        EXPECT_TRUE(sr.infared_sensor);
        EXPECT_FALSE(sr.photo_sensor);
        EXPECT_FALSE(sr.touch_sensor);
    }

    TEST_F(EnvironmentTest, TestCollisionSensor) {
        aich2::Room room = aich2::Room(1,1);
        //aich2::Position robot = aich2::Position(0, 0, aich2::NORTH);
        //aich2::Position home = aich2::Position(0, 0, aich2::NORTH);
        aich2::Environment env = aich2::Environment(&room, &robot, &home);
        //aich2::SensorReading sr;
        env.CommandRobot(aich2::FORWARD);
        env.ReadSensor(&sr);
        EXPECT_TRUE(sr.infared_sensor);
        EXPECT_FALSE(sr.photo_sensor);
        EXPECT_TRUE(sr.touch_sensor);
        env.CommandRobot(aich2::RIGHT_90);
        env.ReadSensor(&sr);
        EXPECT_FALSE(sr.touch_sensor);
    }

    TEST_F(EnvironmentTest, TestHomeSensor) {
        aich2::Room room = aich2::Room(2,2);
        //aich2::Position robot = aich2::Position(0, 0, aich2::EAST);
        //aich2::Position home = aich2::Position(0, 0, aich2::NORTH);
        aich2::Environment env = aich2::Environment(&room, &robot, &home);
        //aich2::SensorReading sr;
        env.ReadSensor(&sr);
        EXPECT_TRUE(sr.infared_sensor);

        env.CommandRobot(aich2::FORWARD);
        env.ReadSensor(&sr);
        EXPECT_FALSE(sr.infared_sensor);
    }

    TEST_F(EnvironmentTest, TestDirtSensor) {
        aich2::Room room = aich2::Room(1,1);
        //aich2::Position robot = aich2::Position(0, 0, aich2::NORTH);
        //aich2::Position home = aich2::Position(0, 0, aich2::NORTH);
        aich2::Environment env = aich2::Environment(&room, &robot, &home);
        //aich2::SensorReading sr;
        room.SetSquare(0, 0, aich2::DIRT);
        env.ReadSensor(&sr);
        EXPECT_TRUE(sr.photo_sensor);
        env.CommandRobot(aich2::CLEAN_DIRT);
        env.ReadSensor(&sr);
        EXPECT_FALSE(sr.photo_sensor);
    }
}