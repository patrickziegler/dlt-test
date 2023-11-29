## Notes

```sh
podman build -f Containerfile -t dlt-test
podman run --detach --rm --name test --log-driver=journald --log-opt=tag=TEST dlt-test
podman kill test; podman ps -a; podman rm -f test
```

## References

- https://github.com/patrickziegler/conmon/compare/main...dlt-logging-lib?diff=unified
