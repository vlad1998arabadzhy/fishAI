include("/home/garuda/CPP_Qt_Projects/FishAI/build/Desktop-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/FishAI-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "/home/garuda/CPP_Qt_Projects/FishAI/build/Desktop-Debug/FishAI"
    GENERATE_QT_CONF
)
