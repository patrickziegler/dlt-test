TAG := dlt-test

.PHONY: all clean

all:
	podman build -f Containerfile -t $(TAG)

clean:
	podman rmi $(TAG)
