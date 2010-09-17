// Copyright (C) 2010 NICTA and the authors listed below
// http://nicta.com.au
// 
// Authors:
// - Conrad Sanderson (conradsand at ieee dot org)
// 
// This file is part of the Armadillo C++ library.
// It is provided without any warranty of fitness
// for any purpose. You can redistribute this file
// and/or modify it under the terms of the GNU
// Lesser General Public License (LGPL) as published
// by the Free Software Foundation, either version 3
// of the License or (at your option) any later version.
// (see http://www.opensource.org/licenses for more info)


#ifndef ARMA_INCLUDES
#define ARMA_INCLUDES


#include "armadillo_bits/config.hpp"
#include "armadillo_bits/compiler_setup.hpp"

#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <complex>
#include <vector>


#if defined(ARMA_HAVE_GETTIMEOFDAY)
  #include <sys/time.h>
  #undef ARMA_USE_BOOST_DATE
#endif


#if defined(ARMA_USE_BOOST)
  #include <boost/math/complex.hpp>
  #include <boost/math/special_functions/acosh.hpp>
  #include <boost/math/special_functions/asinh.hpp>
  #include <boost/math/special_functions/atanh.hpp>
  #include <boost/current_function.hpp>

  #if defined(ARMA_EXTRA_DEBUG)
    #include <boost/format.hpp>
    #define ARMA_USE_BOOST_FORMAT
  #endif
#endif


#if defined(ARMA_USE_BOOST_DATE)
  #include <boost/date_time/posix_time/posix_time.hpp>
#endif


#if defined(ARMA_USE_ATLAS)
  #define ARMA_TMP_STRING(x) x

  #define ARMA_ATLAS_INCLUDE_1 <ARMA_TMP_STRING(ARMA_ATLAS_INCLUDE_DIR)/ARMA_TMP_STRING(cblas.h)>
  #define ARMA_ATLAS_INCLUDE_2 <ARMA_TMP_STRING(ARMA_ATLAS_INCLUDE_DIR)/ARMA_TMP_STRING(clapack.h)>
  
  extern "C"
    {
    #include ARMA_ATLAS_INCLUDE_1
    #include ARMA_ATLAS_INCLUDE_2
    }

  #undef ARMA_TMP_STRING
  #undef ARMA_ATLAS_INCLUDE_1
  #undef ARMA_ATLAS_INCLUDE_2
#endif


#include "armadillo_bits/itpp_wrap.hpp"


//! \namespace arma namespace for Armadillo classes and functions
namespace arma
  {
  
  // preliminaries
  
  #include "armadillo_bits/forward_proto.hpp"
  #include "armadillo_bits/static_assert.hpp"
  #include "armadillo_bits/typedef.hpp"
  #include "armadillo_bits/format_wrap.hpp"
  #include "armadillo_bits/cmath_wrap.hpp"
  #include "armadillo_bits/constants.hpp"
  #include "armadillo_bits/version.hpp"
  #include "armadillo_bits/traits.hpp"
  #include "armadillo_bits/promote_type.hpp"
  #include "armadillo_bits/upgrade_val.hpp"
  #include "armadillo_bits/restrictors.hpp"
  #include "armadillo_bits/access.hpp"
  
  
  //
  // class prototypes
  
  #include "armadillo_bits/syslib_proto.hpp"
  #include "armadillo_bits/podarray_proto.hpp"
  
  #include "armadillo_bits/blas_proto.hpp"
  #include "armadillo_bits/lapack_proto.hpp"
  #include "armadillo_bits/atlas_proto.hpp"
  #include "armadillo_bits/auxlib_proto.hpp"
  
  #include "armadillo_bits/Base.hpp"
  #include "armadillo_bits/BaseCube.hpp"
  
  #include "armadillo_bits/Mat_proto.hpp"
  #include "armadillo_bits/Col_proto.hpp"
  #include "armadillo_bits/Row_proto.hpp"
  #include "armadillo_bits/Cube_proto.hpp"
  
  #include "armadillo_bits/field_proto.hpp"
  #include "armadillo_bits/subview_proto.hpp"
  #include "armadillo_bits/subview_field_proto.hpp"
  #include "armadillo_bits/subview_cube_proto.hpp"
  #include "armadillo_bits/diagview_proto.hpp"
  
  
  #include "armadillo_bits/diskio_proto.hpp"
  #include "armadillo_bits/wall_clock_proto.hpp"
  #include "armadillo_bits/running_stat_proto.hpp"
  #include "armadillo_bits/running_stat_vec_proto.hpp"
  
  #include "armadillo_bits/Op_proto.hpp"
  #include "armadillo_bits/OpCube_proto.hpp"
  
  #include "armadillo_bits/eOp_proto.hpp"
  #include "armadillo_bits/eOpCube_proto.hpp"
  
  
  #include "armadillo_bits/Glue_proto.hpp"
  #include "armadillo_bits/eGlue_proto.hpp"
  
  #include "armadillo_bits/GlueCube_proto.hpp"
  #include "armadillo_bits/eGlueCube_proto.hpp"
  
  #include "armadillo_bits/eop_core_proto.hpp"
  #include "armadillo_bits/eop_cube_core_proto.hpp"
  
  #include "armadillo_bits/eglue_core_proto.hpp"
  #include "armadillo_bits/eglue_cube_core_proto.hpp"
  
  #include "armadillo_bits/op_diagmat_proto.hpp"
  #include "armadillo_bits/op_diagvec_proto.hpp"
  #include "armadillo_bits/op_dot_proto.hpp"
  #include "armadillo_bits/op_inv_proto.hpp"
  #include "armadillo_bits/op_htrans_proto.hpp"
  #include "armadillo_bits/op_max_proto.hpp"
  #include "armadillo_bits/op_min_proto.hpp"
  #include "armadillo_bits/op_mean_proto.hpp"
  #include "armadillo_bits/op_median_proto.hpp"
  #include "armadillo_bits/op_sort_proto.hpp"
  #include "armadillo_bits/op_sum_proto.hpp"
  #include "armadillo_bits/op_stddev_proto.hpp"
  #include "armadillo_bits/op_trans_proto.hpp"
  #include "armadillo_bits/op_var_proto.hpp"
  #include "armadillo_bits/op_repmat_proto.hpp"
  #include "armadillo_bits/op_reshape_proto.hpp"
  #include "armadillo_bits/op_cov_proto.hpp"
  #include "armadillo_bits/op_cor_proto.hpp"
  #include "armadillo_bits/op_shuffle_proto.hpp"
  #include "armadillo_bits/op_prod_proto.hpp"
  #include "armadillo_bits/op_pinv_proto.hpp"
  #include "armadillo_bits/op_dotext_proto.hpp"
  #include "armadillo_bits/op_flip_proto.hpp"
  #include "armadillo_bits/op_princomp_proto.hpp"
  #include "armadillo_bits/op_princomp_cov_proto.hpp"
  
  #include "armadillo_bits/glue_times_proto.hpp"
  #include "armadillo_bits/glue_cov_proto.hpp"
  #include "armadillo_bits/glue_cor_proto.hpp"
  #include "armadillo_bits/glue_kron_proto.hpp"
  #include "armadillo_bits/glue_cross_proto.hpp"
  
  
  //
  // debugging functions
  
  #include "armadillo_bits/debug.hpp"
  
  
  //
  // classes that underlay metaprogramming 
  
  #include "armadillo_bits/Proxy.hpp"
  #include "armadillo_bits/ProxyCube.hpp"
  
  #include "armadillo_bits/diagmat_proxy.hpp"

  #include "armadillo_bits/unwrap.hpp"
  #include "armadillo_bits/unwrap_cube.hpp"

  #include "armadillo_bits/strip.hpp"
  
  #include "armadillo_bits/Op_meat.hpp"
  #include "armadillo_bits/OpCube_meat.hpp"
  
  #include "armadillo_bits/Glue_meat.hpp"
  #include "armadillo_bits/GlueCube_meat.hpp"
  
  #include "armadillo_bits/eop_aux.hpp"
  
  #include "armadillo_bits/eOp_meat.hpp"
  #include "armadillo_bits/eOpCube_meat.hpp"
  
  #include "armadillo_bits/eGlue_meat.hpp"
  #include "armadillo_bits/eGlueCube_meat.hpp"
  
  #include "armadillo_bits/eglue_misc.hpp"
  #include "armadillo_bits/eglue_cube_misc.hpp"
  
  
  //
  // ostream
  
  #include "armadillo_bits/arma_ostream_proto.hpp"
  #include "armadillo_bits/arma_ostream_meat.hpp"
  
  
  //
  // operators
  
  #include "armadillo_bits/operator_plus.hpp"
  #include "armadillo_bits/operator_minus.hpp"
  #include "armadillo_bits/operator_times.hpp"
  #include "armadillo_bits/operator_schur.hpp"
  #include "armadillo_bits/operator_div.hpp"
  #include "armadillo_bits/operator_relational.hpp"
  
  #include "armadillo_bits/operator_cube_plus.hpp"
  #include "armadillo_bits/operator_cube_minus.hpp"
  #include "armadillo_bits/operator_cube_times.hpp"
  #include "armadillo_bits/operator_cube_schur.hpp"
  #include "armadillo_bits/operator_cube_div.hpp"
  #include "armadillo_bits/operator_cube_relational.hpp"
  
  #include "armadillo_bits/operator_ostream.hpp"
  
  
  //
  // user accessible functions
  
  // the order of the fn_*.hpp include files matters,
  // as some files require functionality given in preceding files
  
  #include "armadillo_bits/fn_conv_to.hpp"
  #include "armadillo_bits/fn_min.hpp"
  #include "armadillo_bits/fn_max.hpp"
  #include "armadillo_bits/fn_accu.hpp"
  #include "armadillo_bits/fn_sum.hpp"
  #include "armadillo_bits/fn_diagmat.hpp"
  #include "armadillo_bits/fn_diagvec.hpp"
  #include "armadillo_bits/fn_inv.hpp"
  #include "armadillo_bits/fn_trace.hpp"
  #include "armadillo_bits/fn_trans.hpp"
  #include "armadillo_bits/fn_det.hpp"
  #include "armadillo_bits/fn_log_det.hpp"
  #include "armadillo_bits/fn_eig.hpp"
  #include "armadillo_bits/fn_lu.hpp"
  #include "armadillo_bits/fn_zeros.hpp"
  #include "armadillo_bits/fn_ones.hpp"
  #include "armadillo_bits/fn_misc.hpp"
  #include "armadillo_bits/fn_norm.hpp"
  #include "armadillo_bits/fn_dot.hpp"
  #include "armadillo_bits/fn_rand.hpp"
  #include "armadillo_bits/fn_randn.hpp"
  #include "armadillo_bits/fn_trig.hpp"
  #include "armadillo_bits/fn_mean.hpp"
  #include "armadillo_bits/fn_median.hpp"
  #include "armadillo_bits/fn_stddev.hpp"
  #include "armadillo_bits/fn_var.hpp"
  #include "armadillo_bits/fn_sort.hpp"
  #include "armadillo_bits/fn_sort_index.hpp"
  #include "armadillo_bits/fn_htrans.hpp"
  #include "armadillo_bits/fn_chol.hpp"
  #include "armadillo_bits/fn_qr.hpp"
  #include "armadillo_bits/fn_svd.hpp"
  #include "armadillo_bits/fn_solve.hpp"
  #include "armadillo_bits/fn_repmat.hpp"
  #include "armadillo_bits/fn_reshape.hpp"
  #include "armadillo_bits/fn_cov.hpp"
  #include "armadillo_bits/fn_cor.hpp"
  #include "armadillo_bits/fn_shuffle.hpp"
  #include "armadillo_bits/fn_prod.hpp"
  #include "armadillo_bits/fn_eps.hpp"
  #include "armadillo_bits/fn_pinv.hpp"
  #include "armadillo_bits/fn_rank.hpp"
  #include "armadillo_bits/fn_kron.hpp"
  #include "armadillo_bits/fn_flip.hpp"
  #include "armadillo_bits/fn_as_scalar.hpp"
  #include "armadillo_bits/fn_princomp.hpp"
  #include "armadillo_bits/fn_princomp_cov.hpp"
  #include "armadillo_bits/fn_cross.hpp"
  
  //
  // class meat
  
  #include "armadillo_bits/gemm.hpp"
  #include "armadillo_bits/gemv.hpp"
  #include "armadillo_bits/gemm_mixed.hpp"
  
  #include "armadillo_bits/eop_core_meat.hpp"
  #include "armadillo_bits/eop_cube_core_meat.hpp"
  
  #include "armadillo_bits/eglue_core_meat.hpp"
  #include "armadillo_bits/eglue_cube_core_meat.hpp"
  
  #include "armadillo_bits/podarray_meat.hpp"
  #include "armadillo_bits/auxlib_meat.hpp"
  
  #include "armadillo_bits/Mat_meat.hpp"
  #include "armadillo_bits/Col_meat.hpp"
  #include "armadillo_bits/Row_meat.hpp"
  #include "armadillo_bits/Cube_meat.hpp"
  #include "armadillo_bits/field_meat.hpp"
  #include "armadillo_bits/subview_meat.hpp"
  #include "armadillo_bits/subview_field_meat.hpp"
  #include "armadillo_bits/subview_cube_meat.hpp"
  #include "armadillo_bits/diagview_meat.hpp"
  
  #include "armadillo_bits/diskio_meat.hpp"
  #include "armadillo_bits/wall_clock_meat.hpp"
  #include "armadillo_bits/running_stat_meat.hpp"
  #include "armadillo_bits/running_stat_vec_meat.hpp"
  
  #include "armadillo_bits/op_diagmat_meat.hpp"
  #include "armadillo_bits/op_diagvec_meat.hpp"
  #include "armadillo_bits/op_dot_meat.hpp"
  #include "armadillo_bits/op_inv_meat.hpp"
  #include "armadillo_bits/op_htrans_meat.hpp"
  #include "armadillo_bits/op_max_meat.hpp"
  #include "armadillo_bits/op_min_meat.hpp"
  #include "armadillo_bits/op_mean_meat.hpp"
  #include "armadillo_bits/op_median_meat.hpp"
  #include "armadillo_bits/op_sort_meat.hpp"
  #include "armadillo_bits/op_sum_meat.hpp"
  #include "armadillo_bits/op_stddev_meat.hpp"
  #include "armadillo_bits/op_trans_meat.hpp"
  #include "armadillo_bits/op_var_meat.hpp"
  #include "armadillo_bits/op_repmat_meat.hpp"
  #include "armadillo_bits/op_reshape_meat.hpp"
  #include "armadillo_bits/op_cov_meat.hpp"
  #include "armadillo_bits/op_cor_meat.hpp"
  #include "armadillo_bits/op_shuffle_meat.hpp"
  #include "armadillo_bits/op_prod_meat.hpp"
  #include "armadillo_bits/op_pinv_meat.hpp"
  #include "armadillo_bits/op_dotext_meat.hpp"
  #include "armadillo_bits/op_flip_meat.hpp"
  #include "armadillo_bits/op_princomp_meat.hpp"
  #include "armadillo_bits/op_princomp_cov_meat.hpp"
  
  #include "armadillo_bits/glue_times_meat.hpp"
  #include "armadillo_bits/glue_cov_meat.hpp"
  #include "armadillo_bits/glue_cor_meat.hpp"
  #include "armadillo_bits/glue_kron_meat.hpp"
  #include "armadillo_bits/glue_cross_meat.hpp"
  }
  
#endif

