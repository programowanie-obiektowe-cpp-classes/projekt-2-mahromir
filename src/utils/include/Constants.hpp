#pragma once

namespace Constants {

extern const double PI;

extern const double SPEED_OF_LIGHT;

extern const double IAU_2012_ASTRONOMICAL_UNIT;

/** Solar radius as defined by IAU 2015 resolution B3: 695700000.0 m.
 * @see <a href="https://www.iau.org/static/resolutions/IAU2015_English.pdf">IAU 2015
 * resolutions</a>
 */
extern const double IAU_2015_NOMINAL_SOLAR_RADIUS;

/** Sun attraction coefficient as defined by IAU 2015 resolution B3: 1.3271244e20 (m³/s²). */
extern const double IAU_2015_NOMINAL_SUN_GM;

/** Earth equatorial radius as defined by IAU 2015 resolution B3: 6.3781e6 (m). */
extern const double IAU_2015_NOMINAL_EARTH_EQUATORIAL_RADIUS;

/** Earth polar radius as defined by IAU 2015 resolution B3: 6.3568e6 (m). */
extern const double IAU_2015_NOMINAL_EARTH_POLAR_RADIUS;

/** Earth attraction coefficient as defined by IAU 2015 resolution B3: 3.986004e14 (m³/s²). */
extern const double IAU_2015_NOMINAL_EARTH_GM;

/** Jupiter equatorial radius as defined by IAU 2015 resolution B3: 7.1492e7 (m). */
extern const double IAU_2015_NOMINAL_JUPITER_EQUATORIAL_RADIUS;

/** Jupiter polar radius as defined by IAU 2015 resolution B3: 6.6854e7 (m). */
extern const double IAU_2015_NOMINAL_JUPITER_POLAR_RADIUS;

/** Jupiter attraction coefficient as defined by IAU 2015 resolution B3: 1.2668653e17 (m³/s²). */
extern const double IAU_2015_NOMINAL_JUPITER_GM;

/** Duration of a mean solar day: 86400.0 s. */
extern const double JULIAN_DAY;

/** Duration of a Julian year: 365.25 {@link #JULIAN_DAY}. */
extern const double JULIAN_YEAR;

/** Duration of a Julian century: 36525 {@link #JULIAN_DAY}. */
extern const double JULIAN_CENTURY;

/** Duration of a Besselian year: 365.242198781 {@link #JULIAN_DAY}. */
extern const double BESSELIAN_YEAR;

/** Conversion factor from arc seconds to radians: 2*PI/(360*60*60). */
extern const double ARC_SECONDS_TO_RADIANS;

/** Standard gravity constant, used in maneuvers definition: 9.80665 m/s². */
extern const double G0_STANDARD_GRAVITY;

/** Sun radius: 695700000 m (source: resolution B3 from IAU 2015). */
extern const double SUN_RADIUS;

/** Moon equatorial radius: 1737400 m. */
extern const double MOON_EQUATORIAL_RADIUS;

/** Earth equatorial radius from WGS84 model: 6378137.0 m. */
extern const double WGS84_EARTH_EQUATORIAL_RADIUS;

/** Earth flattening from WGS84 model: 1.0 / 298.257223563. */
extern const double WGS84_EARTH_FLATTENING;

/** Earth angular velocity from WGS84 model: 7.292115e-5 rad/s. */
extern const double WGS84_EARTH_ANGULAR_VELOCITY;

/** Earth gravitational constant from WGS84 model: 3.986004418e14 m³/s². */
extern const double WGS84_EARTH_MU;

/** Earth un-normalized second zonal coefficient from WGS84 model: . */
extern const double WGS84_EARTH_C20;

/** Earth equatorial radius from GRS80 model: 6378137.0 m. */
extern const double GRS80_EARTH_EQUATORIAL_RADIUS;

/** Earth flattening from GRS80 model: 1.0 / 298.257222101. */
extern const double GRS80_EARTH_FLATTENING;

/** Earth angular velocity from GRS80 model: 7.292115e-5 rad/s. */
extern const double GRS80_EARTH_ANGULAR_VELOCITY;

/** Earth gravitational constant from GRS80 model: 3.986005e14 m³/s². */
extern const double GRS80_EARTH_MU;

/** Earth un-normalized second zonal coefficient from GRS80 model: -1.08263e-3. */
extern const double GRS80_EARTH_C20;

/** Earth equatorial radius from EGM96 model: 6378136.3 m. */
extern const double EGM96_EARTH_EQUATORIAL_RADIUS;

/** Earth gravitational constant from EGM96 model: 3.986004415e14 m³/s². */
extern const double EGM96_EARTH_MU;

/** Earth un-normalized second zonal coefficient from EGM96 model: -1.08262668355315e-3. */
extern const double EGM96_EARTH_C20;

/** Earth un-normalized third zonal coefficient from EGM96 model: 2.53265648533224e-6. */
extern const double EGM96_EARTH_C30;

/** Earth un-normalized fourth zonal coefficient from EGM96 model: 1.619621591367e-6. */
extern const double EGM96_EARTH_C40;

/** Earth un-normalized fifth zonal coefficient from EGM96 model: 2.27296082868698e-7. */
extern const double EGM96_EARTH_C50;

/** Earth un-normalized sixth zonal coefficient from EGM96 model: -5.40681239107085e-7. */
extern const double EGM96_EARTH_C60;

/** Earth equatorial radius from GRIM5C1 model: 6378136.46 m. */
extern const double GRIM5C1_EARTH_EQUATORIAL_RADIUS;

/** Earth flattening from GRIM5C1 model: 1.0 / 298.25765. */
extern const double GRIM5C1_EARTH_FLATTENING;

/** Earth angular velocity from GRIM5C1 model: 7.292115e-5 rad/s. */
extern const double GRIM5C1_EARTH_ANGULAR_VELOCITY;

/** Earth gravitational constant from GRIM5C1 model: 3.986004415e14 m³/s². */
extern const double GRIM5C1_EARTH_MU;

/** Earth un-normalized second zonal coefficient from GRIM5C1 model: -1.082626110612609e-3. */
extern const double GRIM5C1_EARTH_C20;

/** Earth un-normalized third zonal coefficient from GRIM5C1 model: 2.536150841690056e-6. */
extern const double GRIM5C1_EARTH_C30;

/** Earth un-normalized fourth zonal coefficient from GRIM5C1 model: 1.61936352497151e-6. */
extern const double GRIM5C1_EARTH_C40;

/** Earth un-normalized fifth zonal coefficient from GRIM5C1 model: 2.231013736607540e-7. */
extern const double GRIM5C1_EARTH_C50;

/** Earth un-normalized sixth zonal coefficient from GRIM5C1 model: -5.402895357302363e-7. */
extern const double GRIM5C1_EARTH_C60;

/** Earth equatorial radius from EIGEN5C model: 6378136.46 m. */
extern const double EIGEN5C_EARTH_EQUATORIAL_RADIUS;

/** Earth gravitational constant from EIGEN5C model: 3.986004415e14 m³/s². */
extern const double EIGEN5C_EARTH_MU;

/** Earth un-normalized second zonal coefficient from EIGEN5C model: -1.082626457231767e-3. */
extern const double EIGEN5C_EARTH_C20;

/** Earth un-normalized third zonal coefficient from EIGEN5C model: 2.532547231862799e-6. */
extern const double EIGEN5C_EARTH_C30;

/** Earth un-normalized fourth zonal coefficient from EIGEN5C model: 1.619964434136e-6. */
extern const double EIGEN5C_EARTH_C40;

/** Earth un-normalized fifth zonal coefficient from EIGEN5C model: 2.277928487005437e-7. */
extern const double EIGEN5C_EARTH_C50;

/** Earth un-normalized sixth zonal coefficient from EIGEN5C model: -5.406653715879098e-7. */
extern const double EIGEN5C_EARTH_C60;

/** Earth equatorial radius from IERS96 model: 6378136.49 m. */
extern const double IERS96_EARTH_EQUATORIAL_RADIUS;

/** Earth flattening from IERS96 model: 1.0 / 298.25642. */
extern const double IERS96_EARTH_FLATTENING;

/** Earth angular velocity from IERS96 model: 7.292115e-5 rad/s. */
extern const double IERS96_EARTH_ANGULAR_VELOCITY;

/** Earth gravitational constant from IERS96 model: 3.986004418e14 m³/s². */
extern const double IERS96_EARTH_MU;

/** Earth un-normalized second zonal coefficient from IERS96 model: -1.0826359e-3. */
extern const double IERS96_EARTH_C20;

/** Earth equatorial radius from IERS2003 model: 6378136.6 m. */
extern const double IERS2003_EARTH_EQUATORIAL_RADIUS;

/** Earth flattening from IERS2003 model: 1.0 / 298.25642. */
extern const double IERS2003_EARTH_FLATTENING;

/** Earth angular velocity from IERS2003 model: 7.292115e-5 rad/s. */
extern const double IERS2003_EARTH_ANGULAR_VELOCITY;

/** Earth gravitational constant from IERS2003 model: 3.986004418e14 m³/s². */
extern const double IERS2003_EARTH_MU;

/** Earth un-normalized second zonal coefficient from IERS2003 model: -1.0826359e-3. */
extern const double IERS2003_EARTH_C20;

/** Earth equatorial radius from IERS2010 model: 6378136.6 m. */
extern const double IERS2010_EARTH_EQUATORIAL_RADIUS;

/** Earth flattening from IERS2010 model: 1.0 / 298.25642. */
extern const double IERS2010_EARTH_FLATTENING;

/** Earth angular velocity from IERS2010 model: 7.292115e-5 rad/s. */
extern const double IERS2010_EARTH_ANGULAR_VELOCITY;

/** Earth gravitational constant from IERS2010 model: 3.986004418e14 m³/s². */
extern const double IERS2010_EARTH_MU;

/** Earth un-normalized second zonal coefficient from IERS2010 model: -1.0826359e-3. */
extern const double IERS2010_EARTH_C20;

/** Gaussian gravitational constant: 0.01720209895 √(AU³/d²). */
extern const double JPL_SSD_GAUSSIAN_GRAVITATIONAL_CONSTANT;

/** Astronomical Unit: 149597870691 m. */
extern const double JPL_SSD_ASTRONOMICAL_UNIT;

/** Sun attraction coefficient (m³/s²). */
extern const double JPL_SSD_SUN_GM;

/** Sun/Mercury mass ratio: 6023600. */
extern const double JPL_SSD_SUN_MERCURY_MASS_RATIO;

/** Sun/Mercury attraction coefficient (m³/s²). */
extern const double JPL_SSD_MERCURY_GM;

/** Sun/Venus mass ratio: 408523.71. */
extern const double JPL_SSD_SUN_VENUS_MASS_RATIO;

/** Sun/Venus attraction coefficient (m³/s²). */
extern const double JPL_SSD_VENUS_GM;

/** Sun/(Earth + Moon) mass ratio: 328900.56. */
extern const double JPL_SSD_SUN_EARTH_PLUS_MOON_MASS_RATIO;

/** Sun/(Earth + Moon) attraction coefficient (m³/s²). */
extern const double JPL_SSD_EARTH_PLUS_MOON_GM;

/** Earth/Moon mass ratio: 81.30059. */
extern const double JPL_SSD_EARTH_MOON_MASS_RATIO;

/** Moon attraction coefficient (m³/s²). */
extern const double JPL_SSD_MOON_GM;

/** Earth attraction coefficient (m³/s²). */
extern const double JPL_SSD_EARTH_GM;

/** Sun/(Mars system) mass ratio: 3098708.0. */
extern const double JPL_SSD_SUN_MARS_SYSTEM_MASS_RATIO;

/** Sun/(Mars system) attraction coefficient (m³/s²). */
extern const double JPL_SSD_MARS_SYSTEM_GM;

/** Sun/(Jupiter system) mass ratio: 1047.3486. */
extern const double JPL_SSD_SUN_JUPITER_SYSTEM_MASS_RATIO;

/** Sun/(Jupiter system) ttraction coefficient (m³/s²). */
extern const double JPL_SSD_JUPITER_SYSTEM_GM;

/** Sun/(Saturn system) mass ratio: 3497.898. */
extern const double JPL_SSD_SUN_SATURN_SYSTEM_MASS_RATIO;

/** Sun/(Saturn system) attraction coefficient (m³/s²). */
extern const double JPL_SSD_SATURN_SYSTEM_GM;

/** Sun/(Uranus system) mass ratio: 22902.98. */
extern const double JPL_SSD_SUN_URANUS_SYSTEM_MASS_RATIO;

/** Sun/(Uranus system) attraction coefficient (m³/s²). */
extern const double JPL_SSD_URANUS_SYSTEM_GM;

/** Sun/(Neptune system) mass ratio: 19412.24. */
extern const double JPL_SSD_SUN_NEPTUNE_SYSTEM_MASS_RATIO;

/** Sun/(Neptune system) attraction coefficient (m³/s²). */
extern const double JPL_SSD_NEPTUNE_SYSTEM_GM;

/** Sun/(Pluto system) mass ratio: 1.35e8. */
extern const double JPL_SSD_SUN_PLUTO_SYSTEM_MASS_RATIO;

/** Sun/(Pluto system) ttraction coefficient (m³/s²). */
extern const double JPL_SSD_PLUTO_SYSTEM_GM;

};  // namespace Constants
