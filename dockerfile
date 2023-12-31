FROM oceanbase/miniob as build

WORKDIR /app

COPY docker-copy .
RUN sed -i 's#http://archive.ubuntu.com/#http://mirrors.tuna.tsinghua.edu.cn/#' /etc/apt/sources.list;
RUN apt-get update && apt-get install -y graphviz && rm -rf /var/lib/apt/lists/* && python3 get-pip.py && rm -f get-pip.py && pip3 install graphviz && pip3 cache purge


CMD ["echo","-e",Usage: sh check.sh [FILE] \n check the input file's lexic,semantic and gramma and then generate picture of the asTree as output.png"]
