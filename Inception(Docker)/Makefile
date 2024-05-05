.PHONY: clean clean-containers clean-images all fclean re show

PROJECT_NAME := inception

all: $(PROJECT_NAME)

clean:
	@rm -rf /Users/jukim2/data/wordpress/* /Users/jukim2/data/nginx/* /Users/jukim2/data/mariadb/*
	@make clean-containers
	@make clean-volumes
	@make clean-images

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

show:
	@docker images -a
	@echo ""
	@docker ps -a
	@echo ""
	@docker volume ls

$(PROJECT_NAME):
	docker compose up -d --build

down:
	docker compose down

re:
	make clean
	docker-compose build --no-cache
	docker compose up -d
