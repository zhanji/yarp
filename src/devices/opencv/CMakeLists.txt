# Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
# Copyright (C) 2006-2010 RobotCub Consortium
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

yarp_prepare_plugin(opencv_grabber
                    CATEGORY device
                    TYPE yarp::dev::OpenCVGrabber
                    INCLUDE OpenCVGrabber.h
                    EXTRA_CONFIG WRAPPER=grabber
                    DEPENDS "YARP_HAS_OPENCV")

if(NOT SKIP_opencv_grabber)
  set(CMAKE_INCLUDE_CURRENT_DIR ON)


  yarp_add_plugin(yarp_opencv OpenCVGrabber.cpp
                              OpenCVGrabber.h)
  target_link_libraries(yarp_opencv PRIVATE YARP::YARP_OS
                                            YARP::YARP_sig
                                            YARP::YARP_dev)
  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS YARP_OS
                                                      YARP_sig
                                                      YARP_dev)

  target_include_directories(yarp_opencv SYSTEM PRIVATE ${OpenCV_INCLUDE_DIRS})
  target_link_libraries(yarp_opencv PRIVATE ${OpenCV_LIBRARIES})
#   list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS OpenCV) (not using targets)

  yarp_install(TARGETS yarp_opencv
               EXPORT YARP_${YARP_PLUGIN_MASTER}
               COMPONENT ${YARP_PLUGIN_MASTER}
               LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
               ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})
  yarp_install(FILES opencv.ini
               COMPONENT ${YARP_PLUGIN_MASTER}
               DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})
  yarp_install(FILES opencv_grabber.xml
               DESTINATION ${YARP_MODULES_INSTALL_DIR})

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  set_property(TARGET yarp_opencv PROPERTY FOLDER "Plugins/Device")
endif()
