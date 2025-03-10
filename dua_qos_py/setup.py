from setuptools import find_packages, setup

package_name = 'dua_qos_py'

setup(
    name=package_name,
    version='1.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name, ['dua_qos_py/dua_qos_reliable.py', 'dua_qos_py/dua_qos_besteffort.py', 'dua_qos_py/dua_qos_persistent.py'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dotX Automation s.r.l.',
    maintainer_email='info@dotxautomation.com',
    description='ROS 2 Quality of Service (QoS) profiles for DUA Python software packages.',
    license='Apache-2.0',
    tests_require=['pytest']
)
