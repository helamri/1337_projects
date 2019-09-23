FROM ruby

RUN apt-get update -y && \
    apt-get upgrade -y && \
	    apt-get install nodejs -y && \
		    gem install rails bundler

			ONBUILD WORKDIR /opt

			ONBUILD RUN rails new app
			ONBUILD WORKDIR /opt/app
			ONBUILD RUN bundle install
			ONBUILD RUN rails generate migration Createit name:string
			ONBUILD RUN rake db:migrate
