# Zest_Security_SecureElement

Zest_Security_SecureElement board support for Zephyr OS.

## Usage

This board enables the following components:

- [Vendor Reference](https://link-to-component) kind of sensor.

:bulb: These drivers should also be added to your workspace:

- [Vendor Reference driver](https://link-to-repository).

:pushpin: This shield defines:

- the default chosen-node-purpose: `zephyr,chosen-node-label` to `reference-node`,
<!-- Get chosen node purpose and chosen node label from [Zephyr documentation](https://docs.zephyrproject.org/latest/build/dts/api/api.html#zephyr-specific-chosen-nodes). -->
- a node-purpose device: `reference-node`.

:triangular_ruler: To use this shield:

- Update your device tree by adding the `ZEST_SECURITY_SECUREELEMENT(port)` macro to the `app.overlay` file.\
  Replace `port` with the number of the Zest_Core port to which the shield is connected, e.g.:

  ```c
  ZEST_SECURITY_SECUREELEMENT(1) /* Zest_Security_SecureElement connected to Zest_Core first port */
  ```

- Activate support for the shield by adding `--shield zest_security_secureelement` to the west command.
