cmake_minimum_required(VERSION 3.21)
project(Projet_C_Gen_Word C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_C_Gen_Word main.c DicoTreatment.c DicoTreatment.h AbrNoms.c AbrNoms.h AbrVerbes.c AbrVerbes.h AbrAdjectifs.c AbrAdjectifs.h)
