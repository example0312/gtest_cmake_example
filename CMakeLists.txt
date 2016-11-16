cmake_minimum_required (VERSION 2.6)
 
# Project Name
SET(PROJECT_NAME hello)

# 외부 라이브러리 위치
SET(LIB_DIR lib)

# HEADER 파일 위치
SET(INCLUDE_DIR include)

# SOURCE 파일 위치
SET(SRC_DIR src)

# main.cpp 위치
SET(MAIN_SRC ${SRC_DIR}/main.cpp)

# SOURCE cpp 파일 위치(main.cpp 제외)
SET(SRCS
    ${SRC_DIR}/hello.cpp
    ${SRC_DIR}/bye.cpp
)

PROJECT(${PROJECT_NAME})

# HEADER파일 위치 설정
INCLUDE_DIRECTORIES(${INCLUDE_DIR})

# PROJECT_NAME 바이너리 파일을 만들기 위해 MAIN_SRC를 SRCS 파일을 이용해서 컴파일
# 최종 PROJECT_NAME 이름으로 바이너리 파일이 생성됨
ADD_EXECUTABLE(${PROJECT_NAME} ${MAIN_SRC} ${SRCS})

################################
# GTest
################################
ADD_SUBDIRECTORY(${LIB_DIR}/gtest-1.7.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${INCLUDE_DIR})

################################
# Unit Tests
################################
SET(TEST_DIR test)

# (Test1) test/helloTest.cpp 추가
SET(HELLO_TEST helloTest)
add_executable(${HELLO_TEST} ${SRCS} ${TEST_DIR}/${HELLO_TEST}.cc)
target_link_libraries(${HELLO_TEST} gtest gtest_main)
add_test(test ${HELLO_TEST})

# (Test2) test/byeTest.cpp 추가
SET(BYE_TEST byeTest)
add_executable(${BYE_TEST} ${SRCS} ${TEST_DIR}/${BYE_TEST}.cc)
target_link_libraries(${BYE_TEST} gtest gtest_main)
add_test(test ${BYE_TEST})
