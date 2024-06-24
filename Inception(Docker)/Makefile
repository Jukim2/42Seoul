.PHONY: clean clean-containers clean-images clean-volumes clean-network all re show

PROJECT_NAME := inception
NETWORK = inception

all: $(PROJECT_NAME)

clean:
	@rm -rf /home/jukim2/data
	@make clean-containers
	@make clean-volumes
	@make clean-images
	@make clean-network

test:
	@echo "$$(docker images -q)"

clean-containers:
	@if [ -n "$$(docker ps -a -q)" ]; then \
		docker stop $$(docker ps -a -q); \
		docker rm $$(docker ps -a -q); \
		echo "Docker ps -a is now empty"; \
	else \
		echo "No docker contianers to remove"; \
	fi

clean-images:
	@if [ -n "$$(docker images -a -q)" ]; then \
		docker rmi -f $$(docker images -a -q); \
		echo "docker images removed"; \
	else \
		echo "No docker images to remove"; \
	fi

clean-volumes:
	@if [ -n "$$(docker volume ls -q)" ]; then \
		docker volume rm $$(docker volume ls -q); \
		echo "docker volumes removed"; \
	else \
		echo "No docker volumes to remove"; \
	fi

clean-network:
	docker network rm $(NETWORK)

show:
	@docker images -a
	@echo ""
	@docker ps -a
	@echo ""
	@docker volume ls

$(PROJECT_NAME):
	mkdir -p /home/jukim2/data/wordpress
	mkdir -p /home/jukim2/data/mariaDB
	docker-compose --file ./srcs/docker-compose.yml up -d --build

up:
	mkdir -p /home/jukim2/data/mariaDB
	mkdir -p /home/jukim2/data/wordpress
	docker-compose --file ./srcs/docker-compose.yml up -d --build
	
down:
	docker-compose --file ./srcs/docker-compose.yml down

re:
	make clean
	docker-compose --file ./srcs/docker-compose.yml build --no-cache
	docker-compose --file ./srcs/docker-compose.yml up -d
