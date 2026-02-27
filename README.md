# Zest_Security_SecureElement

Zest_Security_SecureElement board support for Zephyr OS.

## Usage

This board enables the following components:

- [StSafe-A1xx](https://www.st.com/en/secure-mcus/stsafe-a120.html) Secure Element.

:bulb: These drivers should also be added to your workspace:

- [Zephyr ST StSafe-A1xx](https://github.com/catie-aq/zephyr_st-stsafe-a1xx).

:triangular_ruler: To use this shield:

- Update your device tree by adding the `ZEST_SECURITY_SECUREELEMENT(port)` macro to the `app.overlay` file.\
  Replace `port` with the number of the Zest_Core port to which the shield is connected, e.g.:

  ```c
  ZEST_SECURITY_SECUREELEMENT(1) /* Zest_Security_SecureElement connected to Zest_Core first port */
  ```

- Activate support for the shield by adding `--shield zest_security_secureelement` to the west command or `set(SHIELD zest_security_secureelement)` at the top of your `CMakeLists.txt` file.

## Advanced Usage
This shield can be hardware-modified as shown below.

![Zest_Security_SecureElement Hardware Modifications](./img/resitors.png)

In that case, use the alternate shield overlay variant instead:
- Update your `app.overlay` file by adding the `ZEST_SECURITY_SECUREELEMENT_ALT(port, rst_pin)` macro.
  - `port` is the number of the Zest_Core port to which the shield is connected.
  - `rst_pin` is the GPIO pin number used for the reset signal of the STSafe-A1xx. It is based on the hardware modification shown in the picture above and corresponds to the following table:

| Resistance number | GPIO value |
|-------------------|------------|
| R3                | DIO1       |
| R4                | DIO6       |
| R5                | DIO11      |

- Activate support for the alternate variant of the shield by adding `--shield zest_security_secureelement_alt` to the west command or `set(SHIELD zest_security_secureelement_alt)` at the top of your `CMakeLists.txt` file.
