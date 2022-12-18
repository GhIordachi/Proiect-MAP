FROM gcc:latest
WORKDIR /usr/src/Problema_Turnurilor
COPY Problema_Turnurilor.cpp .
RUN gcc -o Problema_Turnurilor  Problema_Turnurilor.cpp -lstdc++
CMD ["./Problema_Turnurilor"]