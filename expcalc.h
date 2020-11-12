typedef struct
{
   const char *mpc_code;
   char filter;
   double primary_diam, obstruction_diam;   /* in cm */
   double aperture, fwhm;                   /* arcsec */
   double qe;                               /* unitless,  0-1 */
   double readnoise;                        /* counts per pixel */
   double pixel_size;                       /* arcsec */
   double sky_brightness;                   /* magnitudes/arcsec^2 */
   double airmass;                          /* ~ 1/sin(alt) */
   double min_alt, max_alt;                 /* degrees */
   double min_dec, max_dec;                 /* degrees */
   double min_ha, max_ha;                   /* degrees */
   double min_elong, max_elong;             /* degrees */
   double *horizon;                         /* degrees */
   int n_horizon_points;
} expcalc_config_t;

double mag_from_snr_and_exposure( const expcalc_config_t *c,
                              const double snr, const double exposure);
double snr_from_mag_and_exposure( const expcalc_config_t *c,
                              const double mag, const double exposure);
double exposure_from_snr_and_mag( const expcalc_config_t *c,
                              const double snr, const double mag);
int find_expcalc_config_from_mpc_code( const char *mpc_code,
                              FILE *ifile, expcalc_config_t *c);
void free_expcalc_config_t( expcalc_config_t *c);
int is_under_horizon( const double alt, const double az,
                              const expcalc_config_t *c);
