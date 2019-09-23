FROM debian

ENV TSV=3.5.1

RUN apt-get update && apt-get upgrade -y && apt-get install wget bzip2 -y
RUN mkdir /home/teamspeak && cd /home/teamspeak && \
    wget http://dl.4players.de/ts/releases/${TSV}/teamspeak3-server_linux_amd64-${TSV}.tar.bz2 && \
	    tar -jxf teamspeak3-server_linux_amd64-${TSV}.tar.bz2 && \
		    rm teamspeak3-server_linux_amd64-${TSV}.tar.bz2

			EXPOSE 9987/udp
			EXPOSE 30033
			EXPOSE 10011
			ENTRYPOINT ["/home/teamspeak/teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]
#docker run -it --rm --name teamspeak --env TS3SERVER_LICENSE=accept -p 9987:9987/udp -p 10011:10011 -p 30033:30033 teamspeak
