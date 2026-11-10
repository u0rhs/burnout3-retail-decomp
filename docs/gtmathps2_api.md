> Imported 2026-10-21 from `the earlier research repo/docs/gtmathps2_api.md` (commit ccc341b,
> the maintainer's own work; docs/provenance.md). Names and sizes from the E-build link maps; no code.

# GtMathPs2 API (from link maps)

Union of inline functions emitted out-of-line in the -O0 PCH / Debug / Internal maps (sizes in bytes per map). Bodies are not available in any ELF we have; they must be reconstructed from inlined uses.

## (free) (120)

- `GtMathPs2::Abs(GtMathPs2::CGtV3d)`  B3O0PCH:60
- `GtMathPs2::Abs(GtMathPs2::CGtV4d)`  B3O0PCH:60
- `GtMathPs2::AngleBetweenVectors(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:208
- `GtMathPs2::AngleBetweenVectors(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:352
- `GtMathPs2::CompressRotation(GtMathPs2::CGtQuat)`  B3O0PCH:1092
- `GtMathPs2::CosAngleBetweenNormalisedVectors(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:176
- `GtMathPs2::CosFast4(GtMathPs2::CGtV4d)`  B3O0PCH:520
- `GtMathPs2::CreateRotationMatrix2x3(float)`  B3O0PCH:172
- `GtMathPs2::CreateRotationMatrix3x4(GtMathPs2::CGtV3d,float)`  B3O0PCH:1372
- `GtMathPs2::CrossProduct(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:92
- `GtMathPs2::DotProduct(GtMathPs2::CGtQuat,GtMathPs2::CGtQuat)`  B3O0PCH:96
- `GtMathPs2::DotProduct(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:116
- `GtMathPs2::DotProduct(GtMathPs2::CGtV4d,GtMathPs2::CGtV4d)`  B3O0PCH:128
- `GtMathPs2::DotProduct(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)`  B3O0PCH:144
- `GtMathPs2::GetRight(GtMathPs2::CGtQuat)`  B3O0PCH:616
- `GtMathPs2::GetUp(GtMathPs2::CGtQuat)`  B3O0PCH:616
- `GtMathPs2::Interpolate(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::XAxisType)`  B3O0PCH:116
- `GtMathPs2::Interpolate(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::ZAxisType)`  B3O0PCH:116
- `GtMathPs2::Interpolate(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,float)`  B3O0PCH:116
- `GtMathPs2::Interpolate(GtMathPs2::CGtV4d,GtMathPs2::CGtV4d,float)`  B3O0PCH:116
- `GtMathPs2::Interpolate(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,float)`  B3O0PCH:116
- `GtMathPs2::IsEffectivelyEqual(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,float)`  B3O0PCH:308
- `GtMathPs2::IsEffectivelyEqual(const GtMathPs2::CGtMatrix3x4&,const GtMathPs2::CGtMatrix3x4&,float)`  B3O0PCH:264
- `GtMathPs2::Matrix3x4SetLookAt(GtMathPs2::CGtV3d)`  B3O0PCH:100
- `GtMathPs2::Matrix3x4SetLookAt(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:432
- `GtMathPs2::Matrix3x4SetLookAt(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:140
- `GtMathPs2::Matrix3x4SetLookAtPoint(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:168
- `GtMathPs2::Matrix3x4SetLookRight(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:432
- `GtMathPs2::Matrix3x4SetLookRight(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:140
- `GtMathPs2::Matrix3x4SetLookUp(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:432
- `GtMathPs2::Matrix3x4SetLookUp(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:140
- `GtMathPs2::Max(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:80
- `GtMathPs2::Max(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)`  B3O0PCH:176
- `GtMathPs2::Min(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:80
- `GtMathPs2::Min(GtMathPs2::CGtV4d,GtMathPs2::CGtV4d)`  B3O0PCH:80
- `GtMathPs2::Min(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)`  B3O0PCH:176
- `GtMathPs2::Multiply(const GtMathPs2::CGtMatrix3x3&,const GtMathPs2::CGtMatrix3x3&)`  B3O0PCH:60
- `GtMathPs2::Multiply(const GtMathPs2::CGtMatrix3x4&,const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:60
- `GtMathPs2::QueryRotate(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d*,float*,GtMathPs2::CGtV3d*)`  B3O0PCH:1016
- `GtMathPs2::QueryRotateDegenerateUnitAxis(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d*)`  B3O0PCH:1484
- `GtMathPs2::SinCosFast(float)`  B3O0PCH:588
- `GtMathPs2::SinCosFast2(float,float)`  B3O0PCH:632
- `GtMathPs2::Slerp(GtMathPs2::CGtQuat,GtMathPs2::CGtQuat,float)`  B3O0PCH:1360
- `GtMathPs2::Slerp(const GtMathPs2::CGtMatrix3x4&,const GtMathPs2::CGtMatrix3x4&,float,float*)`  B3O0PCH:1172
- `GtMathPs2::TransformPoint(const GtMathPs2::CGtMatrix2x3&,const GtMathPs2::CGtV2d&)`  B3O0PCH:180
- `GtMathPs2::TransformPoint(const GtMathPs2::CGtMatrix3x3&,GtMathPs2::CGtV3d)`  B3O0PCH:100
- `GtMathPs2::TransformPoint(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d)`  B3O0PCH:112
- `GtMathPs2::TransformPoints(const GtMathPs2::CGtMatrix2x3&,GtMathPs2::CGtV2d*,const GtMathPs2::CGtV2d*,int)`  B3O0PCH:132
- `GtMathPs2::TransformPoints(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d*,const GtMathPs2::CGtV3d*,int)`  B3O0PCH:148
- `GtMathPs2::TransformVector(const GtMathPs2::CGtMatrix3x3&,GtMathPs2::CGtV3d)`  B3O0PCH:76
- `GtMathPs2::TransformVector(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d)`  B3O0PCH:100
- `GtMathPs2::TransformVectors(const GtMathPs2::CGtMatrix3x4&,GtMathPs2::CGtV3d*,const GtMathPs2::CGtV3d*,int)`  B3O0PCH:132
- `GtMathPs2::UncompressRotation(unsigned int)`  B3O0PCH:1256
- `GtMathPs2::operator *(GtMathPs2::WAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::WAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::WAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::WAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::WAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::XAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::XAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::XAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::XAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::XAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::YAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::YAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::YAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::YAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::YAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::ZAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::ZAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::ZAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(GtMathPs2::ZAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator *(float,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(float,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(float,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator *(float,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::WAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::WAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::WAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::XAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::XAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::XAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::XAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::YAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::YAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::YAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::YAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::YAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::ZAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::ZAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::ZAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::ZAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(GtMathPs2::ZAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator +(float,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(float,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(float,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator +(float,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::WAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::WAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::WAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::WAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::WAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::XAxisType,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::XAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::XAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::XAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::XAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::YAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::YAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::YAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::YAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::ZAxisType,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::ZAxisType,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::ZAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(GtMathPs2::ZAxisType,float)`  B3O0PCH:80
- `GtMathPs2::operator -(float,GtMathPs2::WAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(float,GtMathPs2::XAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(float,GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::operator -(float,GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::operator <<(CGtStrStream&,GtMathPs2::CGtV3d)`  B3O0PCH:292

## CGtV3d (67)

- `GtMathPs2::CGtV3d::B()`  B3O0PCH:52
- `GtMathPs2::CGtV3d::CGtV3d()`  B3O0PCH:24 B3DEBUG:8 B3INTERN:8 DNAT:8
- `GtMathPs2::CGtV3d::CGtV3d(const GtMathPs2::CGtV3d&)`  B3O0PCH:44
- `GtMathPs2::CGtV3d::CGtV3d(float,float,float)`  B3O0PCH:72
- `GtMathPs2::CGtV3d::ConvertToRwV3d(RwV3d*)`  B3O0PCH:72
- `GtMathPs2::CGtV3d::G()`  B3O0PCH:52
- `GtMathPs2::CGtV3d::GetLength()`  B3O0PCH:140
- `GtMathPs2::CGtV3d::GetRawData()`  B3O0PCH:28
- `GtMathPs2::CGtV3d::GetSquaredLength()`  B3O0PCH:88 B3DEBUG:48 B3INTERN:48
- `GtMathPs2::CGtV3d::GetSquaredLength() const`  DNAT:48
- `GtMathPs2::CGtV3d::IsEffectivelyZero()`  B3O0PCH:104
- `GtMathPs2::CGtV3d::IsValid()`  B3O0PCH:248
- `GtMathPs2::CGtV3d::IsZero()`  B3O0PCH:72
- `GtMathPs2::CGtV3d::Normalise()`  B3O0PCH:144
- `GtMathPs2::CGtV3d::NormaliseFast()`  B3O0PCH:188
- `GtMathPs2::CGtV3d::NormaliseGetLength()`  B3O0PCH:196
- `GtMathPs2::CGtV3d::R()`  B3O0PCH:52
- `GtMathPs2::CGtV3d::Set(GtMathPs2::XAxisType,GtMathPs2::XAxisType,GtMathPs2::XAxisType)`  B3O0PCH:136
- `GtMathPs2::CGtV3d::Set(GtMathPs2::XAxisType,GtMathPs2::YAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:136
- `GtMathPs2::CGtV3d::Set(GtMathPs2::XAxisType,GtMathPs2::ZAxisType,GtMathPs2::YAxisType)`  B3O0PCH:136
- `GtMathPs2::CGtV3d::Set(GtMathPs2::YAxisType,GtMathPs2::YAxisType,GtMathPs2::YAxisType)`  B3O0PCH:136
- `GtMathPs2::CGtV3d::Set(GtMathPs2::ZAxisType,GtMathPs2::ZAxisType,GtMathPs2::ZAxisType)`  B3O0PCH:136
- `GtMathPs2::CGtV3d::Set(float,float,float)`  B3O0PCH:128
- `GtMathPs2::CGtV3d::SetFromRwV3d(const RwV3d*)`  B3O0PCH:72
- `GtMathPs2::CGtV3d::SetX(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetX(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetX(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetX(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetX(float)`  B3O0PCH:48
- `GtMathPs2::CGtV3d::SetY(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetY(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetY(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetY(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetY(float)`  B3O0PCH:48
- `GtMathPs2::CGtV3d::SetZ(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetZ(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetZ(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetZ(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3d::SetZ(float)`  B3O0PCH:48
- `GtMathPs2::CGtV3d::X()`  B3O0PCH:52
- `GtMathPs2::CGtV3d::Y()`  B3O0PCH:52
- `GtMathPs2::CGtV3d::Z()`  B3O0PCH:52
- `GtMathPs2::CGtV3d::Zero()`  B3O0PCH:20
- `GtMathPs2::CGtV3d::operator *(GtMathPs2::CGtV3d)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator *(GtMathPs2::WAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator *(GtMathPs2::XAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator *(GtMathPs2::YAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator *(GtMathPs2::ZAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator *(float)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator *=(GtMathPs2::CGtV3d)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator *=(GtMathPs2::ZAxisType)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator *=(float)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator +(GtMathPs2::CGtV3d)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator +(GtMathPs2::WAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator +=(GtMathPs2::CGtV3d)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator +=(GtMathPs2::WAxisType)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator +=(GtMathPs2::XAxisType)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator +=(float)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator -()`  B3O0PCH:48
- `GtMathPs2::CGtV3d::operator -(GtMathPs2::CGtV3d)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator -(GtMathPs2::WAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV3d::operator -=(GtMathPs2::CGtV3d)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator -=(GtMathPs2::WAxisType)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator -=(float)`  B3O0PCH:76
- `GtMathPs2::CGtV3d::operator /(float)`  B3O0PCH:84
- `GtMathPs2::CGtV3d::operator /=(float)`  B3O0PCH:88
- `GtMathPs2::CGtV3d::operator =(const GtMathPs2::CGtV3d&)`  B3O0PCH:44

## CGtV4d (59)

- `GtMathPs2::CGtV4d::A()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::B()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::CGtV4d()`  B3O0PCH:24 B3DEBUG:8 B3INTERN:8
- `GtMathPs2::CGtV4d::CGtV4d(const GtMathPs2::CGtV4d&)`  B3O0PCH:44 B3DEBUG:16 B3INTERN:16 DNAT:16
- `GtMathPs2::CGtV4d::CGtV4d(float,float,float,float)`  B3O0PCH:84
- `GtMathPs2::CGtV4d::G()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::GetRawData()`  B3O0PCH:28
- `GtMathPs2::CGtV4d::GetSquaredLength()`  B3O0PCH:104
- `GtMathPs2::CGtV4d::R()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::Set(float,float,float,float)`  B3O0PCH:80
- `GtMathPs2::CGtV4d::SetA(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetA(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetB(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetB(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetG(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetG(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetR(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetR(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetW(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetW(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetW(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetW(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetW(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetX(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetX(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetX(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetX(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetX(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetY(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetY(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetY(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetY(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetY(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::SetZ(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetZ(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetZ(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetZ(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV4d::SetZ(float)`  B3O0PCH:48
- `GtMathPs2::CGtV4d::W()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::X()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::Y()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::Z()`  B3O0PCH:52
- `GtMathPs2::CGtV4d::Zero()`  B3O0PCH:20
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::CGtV4d)`  B3O0PCH:68 B3DEBUG:20 B3INTERN:20
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::CGtV4d) const`  DNAT:20
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::WAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::XAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::YAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::ZAxisType)`  B3O0PCH:68
- `GtMathPs2::CGtV4d::operator *(float)`  B3O0PCH:68 B3DEBUG:24 B3INTERN:24
- `GtMathPs2::CGtV4d::operator *(float) const`  DNAT:24
- `GtMathPs2::CGtV4d::operator *=(GtMathPs2::CGtV4d)`  B3O0PCH:76
- `GtMathPs2::CGtV4d::operator *=(float)`  B3O0PCH:76
- `GtMathPs2::CGtV4d::operator +(GtMathPs2::CGtV4d)`  B3O0PCH:68
- `GtMathPs2::CGtV4d::operator +=(GtMathPs2::CGtV4d)`  B3O0PCH:76
- `GtMathPs2::CGtV4d::operator -(GtMathPs2::CGtV4d)`  B3O0PCH:68
- `GtMathPs2::CGtV4d::operator /(float)`  B3O0PCH:84
- `GtMathPs2::CGtV4d::operator =(const GtMathPs2::CGtV4d&)`  B3O0PCH:44 B3DEBUG:16 B3INTERN:16 DNAT:16
- `GtMathPs2::CGtV4d::operator ==(GtMathPs2::CGtV4d)`  B3O0PCH:464

## CGtV2d (35)

- `GtMathPs2::CGtV2d::CGtV2d()`  B3O0PCH:24 B3DEBUG:8 B3INTERN:8 DNAT:8
- `GtMathPs2::CGtV2d::CGtV2d(const GtMathPs2::CGtV2d&)`  B3O0PCH:52 B3DEBUG:24 B3INTERN:24 DNAT:24
- `GtMathPs2::CGtV2d::CGtV2d(float,float)`  B3O0PCH:56 B3DEBUG:16 B3INTERN:16 DNAT:16
- `GtMathPs2::CGtV2d::GetLength()`  B3O0PCH:96
- `GtMathPs2::CGtV2d::GetSquaredLength()`  B3O0PCH:80
- `GtMathPs2::CGtV2d::IsZero()`  B3O0PCH:108
- `GtMathPs2::CGtV2d::Normalise()`  B3O0PCH:112
- `GtMathPs2::CGtV2d::Set(float,float)`  B3O0PCH:52
- `GtMathPs2::CGtV2d::SetFromRwV2d(const RwV2d*)`  B3O0PCH:56
- `GtMathPs2::CGtV2d::SetU(float)`  B3O0PCH:36
- `GtMathPs2::CGtV2d::SetV(float)`  B3O0PCH:36
- `GtMathPs2::CGtV2d::SetX(float)`  B3O0PCH:36
- `GtMathPs2::CGtV2d::SetY(float)`  B3O0PCH:36
- `GtMathPs2::CGtV2d::U()`  B3O0PCH:28
- `GtMathPs2::CGtV2d::V()`  B3O0PCH:28
- `GtMathPs2::CGtV2d::X()`  B3O0PCH:28
- `GtMathPs2::CGtV2d::Y()`  B3O0PCH:28
- `GtMathPs2::CGtV2d::Zero()`  B3O0PCH:72
- `GtMathPs2::CGtV2d::operator *(const GtMathPs2::CGtV2d&)`  B3O0PCH:120 B3DEBUG:52 B3INTERN:52
- `GtMathPs2::CGtV2d::operator *(const GtMathPs2::CGtV2d&) const`  DNAT:52
- `GtMathPs2::CGtV2d::operator *(float)`  B3O0PCH:112
- `GtMathPs2::CGtV2d::operator *=(const GtMathPs2::CGtV2d&)`  B3O0PCH:104
- `GtMathPs2::CGtV2d::operator *=(float)`  B3O0PCH:96
- `GtMathPs2::CGtV2d::operator +(const GtMathPs2::CGtV2d&)`  B3O0PCH:120 B3DEBUG:52 B3INTERN:52
- `GtMathPs2::CGtV2d::operator +(const GtMathPs2::CGtV2d&) const`  DNAT:52
- `GtMathPs2::CGtV2d::operator +=(const GtMathPs2::CGtV2d&)`  B3O0PCH:104
- `GtMathPs2::CGtV2d::operator +=(float)`  B3O0PCH:96
- `GtMathPs2::CGtV2d::operator -()`  B3O0PCH:84
- `GtMathPs2::CGtV2d::operator -(const GtMathPs2::CGtV2d&)`  B3O0PCH:120
- `GtMathPs2::CGtV2d::operator -=(const GtMathPs2::CGtV2d&)`  B3O0PCH:104
- `GtMathPs2::CGtV2d::operator /(const GtMathPs2::CGtV2d&)`  B3O0PCH:120
- `GtMathPs2::CGtV2d::operator /(float)`  B3O0PCH:128
- `GtMathPs2::CGtV2d::operator /=(const GtMathPs2::CGtV2d&)`  B3O0PCH:104
- `GtMathPs2::CGtV2d::operator /=(float)`  B3O0PCH:112
- `GtMathPs2::CGtV2d::operator =(const GtMathPs2::CGtV2d&)`  B3O0PCH:52 B3DEBUG:24 B3INTERN:24 DNAT:24

## CGtMatrix3x4 (14)

- `GtMathPs2::CGtMatrix3x4::CGtMatrix3x4()`  B3O0PCH:92
- `GtMathPs2::CGtMatrix3x4::CGtMatrix3x4(const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:124
- `GtMathPs2::CGtMatrix3x4::ConvertToRwMatrix(RwMatrixTag*)`  B3O0PCH:132
- `GtMathPs2::CGtMatrix3x4::Invert()`  B3O0PCH:524
- `GtMathPs2::CGtMatrix3x4::IsNormal()`  B3O0PCH:268
- `GtMathPs2::CGtMatrix3x4::IsOrthogonal()`  B3O0PCH:244
- `GtMathPs2::CGtMatrix3x4::IsValid()`  B3O0PCH:200
- `GtMathPs2::CGtMatrix3x4::OrthoNormalise()`  B3O0PCH:1552
- `GtMathPs2::CGtMatrix3x4::Set(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d)`  B3O0PCH:184
- `GtMathPs2::CGtMatrix3x4::SetFromRwMatrix(const RwMatrixTag*)`  B3O0PCH:140
- `GtMathPs2::CGtMatrix3x4::SetIdentity()`  B3O0PCH:144
- `GtMathPs2::CGtMatrix3x4::operator *(const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:340
- `GtMathPs2::CGtMatrix3x4::operator *=(const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:176
- `GtMathPs2::CGtMatrix3x4::operator =(const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:116

## CGtV3dPlus (10)

- `GtMathPs2::CGtV3dPlus::GetRawData()`  B3O0PCH:28
- `GtMathPs2::CGtV3dPlus::GtV3d()`  B3O0PCH:52
- `GtMathPs2::CGtV3dPlus::Plus()`  B3O0PCH:52
- `GtMathPs2::CGtV3dPlus::SetGtV3d(GtMathPs2::CGtV3d)`  B3O0PCH:56
- `GtMathPs2::CGtV3dPlus::SetPlus(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtV3dPlus::SetPlus(GtMathPs2::YAxisType)`  B3O0PCH:80
- `GtMathPs2::CGtV3dPlus::SetPlus(GtMathPs2::ZAxisType)`  B3O0PCH:80
- `GtMathPs2::CGtV3dPlus::SetPlus(float)`  B3O0PCH:72
- `GtMathPs2::CGtV3dPlus::Zero()`  B3O0PCH:28
- `GtMathPs2::CGtV3dPlus::operator =(const GtMathPs2::CGtV3dPlus&)`  B3O0PCH:44

## CGtQuat (9)

- `GtMathPs2::CGtQuat::CGtQuat()`  B3O0PCH:44
- `GtMathPs2::CGtQuat::CGtQuat(GtMathPs2::CGtV4d)`  B3O0PCH:68 B3DEBUG:16 B3INTERN:16 DNAT:16
- `GtMathPs2::CGtQuat::CGtQuat(const GtMathPs2::CGtQuat&)`  B3O0PCH:52 B3DEBUG:16 B3INTERN:16 DNAT:16
- `GtMathPs2::CGtQuat::ConvertToMatrix()`  B3O0PCH:996
- `GtMathPs2::CGtQuat::GetSquaredLength()`  B3O0PCH:52
- `GtMathPs2::CGtQuat::IsUnit()`  B3O0PCH:96
- `GtMathPs2::CGtQuat::SetFromMatrix(const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:2432
- `GtMathPs2::CGtQuat::operator *(float)`  B3O0PCH:88
- `GtMathPs2::CGtQuat::operator =(const GtMathPs2::CGtQuat&)`  B3O0PCH:44

## CGtPlane (9)

- `GtMathPs2::CGtPlane::Distance()`  B3O0PCH:52
- `GtMathPs2::CGtPlane::GetRawData()`  B3O0PCH:28
- `GtMathPs2::CGtPlane::Normal()`  B3O0PCH:52
- `GtMathPs2::CGtPlane::SetDistance(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtPlane::SetDistance(GtMathPs2::YAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtPlane::SetDistance(GtMathPs2::ZAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtPlane::SetDistance(float)`  B3O0PCH:48
- `GtMathPs2::CGtPlane::SetNormal(GtMathPs2::CGtV3d)`  B3O0PCH:56
- `GtMathPs2::CGtPlane::operator =(const GtMathPs2::CGtPlane&)`  B3O0PCH:44

## CGtSphere (7)

- `GtMathPs2::CGtSphere::Position()`  B3O0PCH:52
- `GtMathPs2::CGtSphere::Radius()`  B3O0PCH:52
- `GtMathPs2::CGtSphere::SetPosition(GtMathPs2::CGtV3d)`  B3O0PCH:56
- `GtMathPs2::CGtSphere::SetRadius(GtMathPs2::WAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtSphere::SetRadius(GtMathPs2::XAxisType)`  B3O0PCH:56
- `GtMathPs2::CGtSphere::SetRadius(float)`  B3O0PCH:48
- `GtMathPs2::CGtSphere::operator =(const GtMathPs2::CGtSphere&)`  B3O0PCH:44

## XAxisType (5)

- `GtMathPs2::XAxisType::XAxisType()`  B3O0PCH:24
- `GtMathPs2::XAxisType::XAxisType(const GtMathPs2::XAxisType&)`  B3O0PCH:44
- `GtMathPs2::XAxisType::operator -()`  B3O0PCH:48
- `GtMathPs2::XAxisType::operator =(const GtMathPs2::XAxisType&)`  B3O0PCH:44
- `GtMathPs2::XAxisType::operator float()`  B3O0PCH:24 B3DEBUG:16

## CGtMatrix3x3 (5)

- `GtMathPs2::CGtMatrix3x3::CGtMatrix3x3()`  B3O0PCH:76 B3DEBUG:8 B3INTERN:8 DNAT:8
- `GtMathPs2::CGtMatrix3x3::CGtMatrix3x3(const GtMathPs2::CGtMatrix3x3&)`  B3O0PCH:100
- `GtMathPs2::CGtMatrix3x3::Invert()`  B3O0PCH:292
- `GtMathPs2::CGtMatrix3x3::operator *(const GtMathPs2::CGtMatrix3x3&)`  B3O0PCH:268
- `GtMathPs2::CGtMatrix3x3::operator =(const GtMathPs2::CGtMatrix3x3&)`  B3O0PCH:92

## CGtQuatPos (4)

- `GtMathPs2::CGtQuatPos::CGtQuatPos()`  B3O0PCH:60
- `GtMathPs2::CGtQuatPos::ConvertToMatrix()`  B3O0PCH:112
- `GtMathPs2::CGtQuatPos::SetFromMatrix(const GtMathPs2::CGtMatrix3x4&)`  B3O0PCH:72
- `GtMathPs2::CGtQuatPos::operator =(const GtMathPs2::CGtQuatPos&)`  B3O0PCH:68

## CGtMatrix2x3 (3)

- `GtMathPs2::CGtMatrix2x3::CGtMatrix2x3()`  B3O0PCH:76
- `GtMathPs2::CGtMatrix2x3::CGtMatrix2x3(const GtMathPs2::CGtMatrix2x3&)`  B3O0PCH:100 B3DEBUG:56 B3INTERN:56 DNAT:56
- `GtMathPs2::CGtMatrix2x3::operator =(const GtMathPs2::CGtMatrix2x3&)`  B3O0PCH:92 B3DEBUG:32 B3INTERN:32 DNAT:32

## WAxisType (2)

- `GtMathPs2::WAxisType::operator -()`  B3O0PCH:48
- `GtMathPs2::WAxisType::operator float()`  B3O0PCH:36

## ZAxisType (2)

- `GtMathPs2::ZAxisType::operator -()`  B3O0PCH:48
- `GtMathPs2::ZAxisType::operator float()`  B3O0PCH:36

## YAxisType (2)

- `GtMathPs2::YAxisType::operator -()`  B3O0PCH:48
- `GtMathPs2::YAxisType::operator float()`  B3O0PCH:36

## CGtMatrix4x4 (2)

- `GtMathPs2::CGtMatrix4x4::CGtMatrix4x4()`  B3O0PCH:92
- `GtMathPs2::CGtMatrix4x4::CGtMatrix4x4(float,float,float,float,float,float,float,float,float,float,float,float,float,float,float`  B3O0PCH:248

## Recovered bodies (DNAT_200.45)

Out-of-line copies in the Jun 8 2004 prototype's executable (`orig/dnat/DNAT_200.45`, extracted from the disc in
`<local archive>/Releases/Prototype`), located with `tools/dnat_align.py`: the disc's `DNAT_200.MAP` is shifted against
that executable by a region-dependent offset, recovered by lining up the map's neighbouring functions (score 18-25
of 25 for each body below; `GetSquaredLength` lands on 0x29F230, the address this header already cited). [C] these
are the compiled bodies; the two `B3NetworkPlayer.cpp` copies (`__ct__Q29GtMathPs26CGtV3dF1`,
`__ct__Q29GtMathPs29XAxisTypeF1`) did not align (score 4/25) and are not listed.

- `__ct__Q29GtMathPs26CGtV4dF1 @0x130090`:  `sq a1,0(a0); jr ra; move v0,a0`
- `GtMathPs2::CGtV3d::CGtV3d() @0x1690B0`:  `jr ra; move v0,a0`
- `GtMathPs2::CGtMatrix3x3::CGtMatrix3x3() @0x1690C0`:  `jr ra; move v0,a0`
- `GtMathPs2::CGtV4d::operator =(const GtMathPs2::CGtV4d&) @0x198790`:  `lq v1,0(a1); move v0,a0; jr ra; sq v1,0(a0)`
- `GtMathPs2::CGtV2d::operator =(const GtMathPs2::CGtV2d&) @0x1987A0`:  `lwc1 $f1,0(a1); move v0,a0; lwc1 $f0,4(a1); swc1 $f1,0(a0); jr ra; swc1 $f0,4(a0)`
- `GtMathPs2::CGtV4d::operator *(GtMathPs2::CGtV4d) const @0x1987D0`:  `lqc2 $vf1,0(a2); lqc2 $vf2,0(a1); vmul.xyzw $vf1xyzw,$vf2xyzw,$vf1xyzw; jr ra; sqc2 $vf1,0(a0)`
- `GtMathPs2::CGtV2d::operator +(const GtMathPs2::CGtV2d&) const @0x1987F0`:  `addiu sp,sp,-16; lwc1 $f3,0(a1); lwc1 $f2,0(a2); lwc1 $f1,4(a1); lwc1 $f0,4(a2); add.s $f2,$f3,$f2; add.s $f0,$f1,$f0; swc1 $f2,0(a0); swc1 $f2,8(sp); swc1 $f0,12(sp); swc1 $f0,4(a0); jr ra; addiu sp,sp,16`
- `GtMathPs2::CGtV2d::operator *(const GtMathPs2::CGtV2d&) const @0x198830`:  `addiu sp,sp,-16; lwc1 $f3,0(a1); lwc1 $f2,0(a2); lwc1 $f1,4(a1); lwc1 $f0,4(a2); mul.s $f2,$f3,$f2; mul.s $f0,$f1,$f0; swc1 $f2,0(a0); swc1 $f2,8(sp); swc1 $f0,12(sp); swc1 $f0,4(a0); jr ra; addiu sp,sp,16`
- `GtMathPs2::CGtV2d::CGtV2d(const GtMathPs2::CGtV2d&) @0x198870`:  `lwc1 $f1,0(a1); move v0,a0; lwc1 $f0,4(a1); swc1 $f1,0(a0); jr ra; swc1 $f0,4(a0)`
- `GtMathPs2::CGtV2d::CGtV2d(float,float) @0x198890`:  `swc1 $f12,0(a0); move v0,a0; jr ra; swc1 $f13,4(a0)`
- `GtMathPs2::CGtV2d::CGtV2d() @0x2042E0`:  `jr ra; move v0,a0`
- `GtMathPs2::CGtV4d::CGtV4d(const GtMathPs2::CGtV4d&) @0x29E840`:  `lq v1,0(a1); move v0,a0; jr ra; sq v1,0(a0)`
- `GtMathPs2::CGtV4d::operator *(float) const @0x29E850`:  `mfc1 v1,$f12; lqc2 $vf1,0(a1); qmtc2 v1,$vf2; vmulx.xyzw $vf1xyzw,$vf1xyzw,$vf2x; jr ra; sqc2 $vf1,0(a0)`
- `GtMathPs2::CGtV3d::GetSquaredLength() const @0x29F230`:  `lqc2 $vf2,0(a1); vaddw.x $vf1x,$vf0x,$vf0w; vmul.xyz $vf2xyz,$vf2xyz,$vf2xyz; qmfc2 a1,$vf2; qmfc2 v1,$vf1; qmtc2 a1,$vf2; vadday.x $ACCx,$vf2x,$vf2y; qmtc2 v1,$vf1; vmaddz.x $vf1x,$vf1x,$vf2z; qmfc2 v1,$vf1; jr ra; sq v1,0(a0)`
- `GtMathPs2::CGtQuat::CGtQuat(const GtMathPs2::CGtQuat&) @0x29F260`:  `lq v1,0(a1); move v0,a0; jr ra; sq v1,0(a0)`
- `GtMathPs2::CGtQuat::CGtQuat(GtMathPs2::CGtV4d) @0x29F270`:  `lq v1,0(a1); move v0,a0; jr ra; sq v1,0(a0)`
- `GtMathPs2::CGtMatrix2x3::operator =(const GtMathPs2::CGtMatrix2x3&) @0x2CD1C0`:  `ld a3,0(a1); move v0,a0; ld a2,8(a1); ld v1,16(a1); sd a3,0(a0); sd a2,8(a0); jr ra; sd v1,16(a0)`
- `GtMathPs2::CGtMatrix2x3::CGtMatrix2x3(const GtMathPs2::CGtMatrix2x3&) @0x2CD1E0`:  `lwc1 $f5,0(a1); move v0,a0; lwc1 $f4,4(a1); lwc1 $f3,8(a1); lwc1 $f2,12(a1); lwc1 $f1,16(a1); lwc1 $f0,20(a1); swc1 $f5,0(a0); swc1 $f4,4(a0); swc1 $f3,8(a0); swc1 $f2,12(a0); swc1 $f1,16(a0); jr ra; swc1 $f0,20(a0)`
