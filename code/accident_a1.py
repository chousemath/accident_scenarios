"""Code snippet for scenario a1"""


def accident_detected(vel: float, accel: float) -> bool:
    """Determines whether or not an accident has occurred"""
    if vel >= 15 and accel >= 4:
        return True
    return False


assert accident_detected(15, 4)
assert accident_detected(16, 5)
assert not accident_detected(13, 4)
assert not accident_detected(15, 3)
