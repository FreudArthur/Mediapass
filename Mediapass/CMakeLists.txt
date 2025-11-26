cmake_minimum_required(VERSION 3.31)
project(Mediapass)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mediapass
        main.cpp
        Utilisateur.cpp
        Patient.cpp
        DossierMedical.cpp
        Consultation.cpp
)

