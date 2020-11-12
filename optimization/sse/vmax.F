      program calc_vmax

      integer :: mesh_x, mesh_y, mesh_z, kx, ky, kz, kxmax, kzmax
      integer :: iounit = 10
      real(8), dimension(:,:,:), allocatable :: vhills
      real(8) :: vmax

c     //   read makecube.cube

      open ( iounit, file = "makecube.cube" )

      read( iounit, * )
      read( iounit, * )
      read( iounit, * )
      read( iounit, * ) mesh_x
      read( iounit, * ) mesh_y
      read( iounit, * ) mesh_z

      allocate( vhills(mesh_x,mesh_y,mesh_z) )

      do kx = 1, mesh_x
      do ky = 1, mesh_y
      do kz = 1, mesh_z
         read( iounit, * ) vhills(kx,ky,kz)
      end do
      end do
      end do

      close( iounit )

c     //   calculate and print vmax

      open ( iounit, file = "vmax.out" )

      do ky = 1, mesh_y

         vmax = 0.d0
         kxmax = 0
         kzmax = 0

         do kx = 1, mesh_x
         do kz = 1, mesh_z
            if ( vhills(kx,ky,kz) .gt. vmax ) then
               vmax = vhills(kx,ky,kz)
               kxmax = kx
               kzmax = kz
            end if
         end do
         end do

         write( iounit, '(3i5,f20.10)' ) kxmax, ky, kzmax, vmax

      end do

      close( iounit )

      stop
      end

