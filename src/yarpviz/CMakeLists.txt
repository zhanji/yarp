# Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

if(CREATE_YARPVIZ)

  project(yarpviz)

  include(YarpUseQt5)
  include(YarpOSXUtilities)

  add_subdirectory(src)
  add_subdirectory(app)

endif()
